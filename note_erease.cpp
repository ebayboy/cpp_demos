/* ԭ��ƥ��һ�飬���δ���� :
 * ���ٹ�������ƥ�䴮�Ƿ����ע���ַ������е��ַ��� ���û������з���
 * �������ȥ��ע�ͺ���ƥ��һ��
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int comp_paras_check_repeat_need_todo(const char *in, int ilen);
static char* textFileRead(const char* filename);

enum {
	/* COMMON Code Note, include MYSQL/XSS/C ... */
	STATE_0 = 0,  /*����״̬*/
	STATE_1,  /* /  */    /* XSS + MYSQL + ���� */
	STATE_2, /* //  */
	STATE_3,  /* *  */  /* XSS + MYSQL + ���� */
	STATE_4,  /* * */
	STATE_5,  /* '  �������ַ���ʼ */
	STATE_6,  /* '\  ������\�ַ� */
	STATE_7,  /* "  ˫�����ַ�����ʼ */
	STATE_8,  /* "\  ˫����\���л����ַ� */

	/**
	 *  MYSQL Code Note # ע�͵��к��������
	 *  MYSQL Code NOte -- ע�͵��к��������
	 *  XSS Code Note --> ע�͵��к��������
	 **/
	STATE_9,  /* # MYSQL����ע�ͺ������� */

	/* STATE_10 */
	STATE_10,  /* - MYSQL && XSS ����ע�ͺ������� */
	STATE_11,  /* - MYSQL && XSS ����ע�ͺ������� */
	STATE_12,  /* space MYSQL ����ע�ͺ������� */
	STATE_13,  /* > XSS ����ע�ͺ������� */

	/* XSS Code Note */
	/* STATE_31 */
	STATE_14, /* < */
	STATE_15, /* !  */
	STATE_16, /* -  */
	STATE_17, /* -  */
	STATE_18, /* -  */
	STATE_19, /* -  */
	STATE_20, /* >  */

	STATE_MAX
};

char comp_states[STATE_MAX + 1] = {
	'\0',   //STATE_0
	'/',    //STATE_1
	'/',    //STATE_2
	'*',    //STATE_3
	'*',    //STATE_4
	'\'',   //STATE_5
	'\\',   //STATE_6
	'\"',   //STATE_7
	'\\',   //STATE_8

	'#',    //STATE_9

	'-',    //STATE_10
	'-',    //STATE_11
	' ',    //STATE_12
	'>',    //STATE_13

	'<',    //STATE_14
	'!',    //STATE_15
	'-',    //STATE_16
	'-',    //STATE_17
	'-',    //STATE_18
	'-',    //STATE_19
	'>',    //STATE_20

	'\0'    //STATE_MAX
};


static int comp_paras_note_state_hit(char ch) {
	int i = 0;

	for (i = STATE_1; i < STATE_MAX; i++) {
		if (comp_states[i] == ch) {
			return i;
		}
	}

	return STATE_0;
}

/* FUNCTION�� ���ټ��һ���Ƿ����ע�͵Ŀ�ʼ״̬���ַ� */
static int comp_paras_check_note_need_todo(const char *in, int ilen) {
	int i, state;
	if (in == NULL || ilen == 0) {
		return 0;
	}

	for (i = 0; i < ilen; i++ ) {
		state = comp_paras_note_state_hit(in[i]);
		if ( state == STATE_1
				|| state == STATE_5
				|| state == STATE_7
				|| state == STATE_9
				|| state == STATE_10
				|| state == STATE_14) {
			return 1;
		}
	}

	return 0;
}

static int comp_paras_check_note_do(const char *in, int ilen, char **out, int *olen) {
	const char *ch = NULL;
	char *tmp = NULL;
	int icount = 0;
	int state = STATE_0;
	int count = 0;

	if (in == NULL || ilen == 0 ) {
		return 0;
	}

	ch = in;

	if (comp_paras_check_repeat_need_todo(in, ilen) == 0) {
		return 0;
	}

	*olen = 0;
	if ((*out = (char *)malloc(ilen + 1)) == NULL) {
		return -1;
	}
	memset(*out, 0, ilen + 1);
	tmp = *out;

	while(ch < in + ilen) {
		//printf("%s:%d process: ch[%c] state:%d\n", __func__, __LINE__, *ch, state);

		/*״̬0��״̬�л�*/
		if(state==STATE_0 && *ch == comp_states[STATE_1]) {
			state = STATE_1;
			ch++;
			continue;
		} else if(state ==STATE_0 && *ch ==comp_states[STATE_5]) {
			state = STATE_5;
			*tmp++ = *ch;
			count++;
		} else if(state ==STATE_0 && *ch ==comp_states[STATE_7]) {
			state = STATE_7;
			*tmp++ = *ch;
			count++;
		} else if(state ==STATE_0 && *ch ==comp_states[STATE_9]) {
			state = STATE_9;
			ch++;
			continue;
		} else if(state ==STATE_0 && *ch ==comp_states[STATE_10]) {
			state = STATE_10;
			ch++;
			continue;
		} else if(state ==STATE_10 && *ch ==comp_states[STATE_11]) {
			state = STATE_11;
			ch++;
			continue;
		} else if(state ==STATE_10 && *ch !=comp_states[STATE_11]) {
			state = STATE_0;
		} else if(state ==STATE_0 && *ch ==comp_states[STATE_14]) {
			state = STATE_14;
			ch++;
			continue;
		} 

		/* ================= BEFORE STATE ENTRANCE ==================== */

		else if(state==STATE_1 && *ch ==comp_states[STATE_2]) {
			/* state entrace */
			state = STATE_2;
		} else if(state==STATE_1 && *ch ==comp_states[STATE_3]) {
			state = STATE_3;
		} else if(state==STATE_1) {
			state = STATE_0;
			*tmp++ = '/';   /* ���� 5/3 ����� */
			count++;
			*tmp++ = *ch;
			count++;

			/*״̬2���л�*/
		} else if(state == STATE_5 && *ch == comp_states[STATE_6]) {
			state = STATE_6;
			*tmp++ = *ch;
			count++;
		} else if(state == STATE_5 && *ch == '\'') {
			state = STATE_0;
			*tmp++ = *ch;
			count++;
		} else if(state == STATE_5) {
			state = STATE_5;
			*tmp++ = *ch;
			count++;

			/*״̬6�л�*/
		}  else if(state == STATE_7 && *ch == comp_states[STATE_8]) {
			state = STATE_8;
			*tmp++ = *ch;
			count++;
		} else if(state == STATE_7 && *ch =='\"') {
			state = STATE_0;
			*tmp++ = *ch;
			count++;
		} else if(state == STATE_7) {
			state = STATE_7;
			*tmp++ = *ch;
			count++;

			/*״̬8���л�*/
		} else if (state == STATE_0) {
			*tmp++ = *ch;
			count++;
			//printf("%s:%d ch=[%c],state=%d *olen:%d *out:[%s]\n", __func__, __LINE__, *ch, state, count, *out);
			ch++;
			continue;
		}

		/* 9-> 10 */
		else if(state == STATE_9 && *ch == '\n') {
			state = STATE_0;
			*tmp++ = '\n';
		} else if (state == STATE_9) {
			state == STATE_9;
		}
		/* 10 -> 11 */
		else if(state ==STATE_10 && *ch == comp_states[STATE_11]) {
			state = STATE_11;
			ch++;
			continue;
		} else if(state ==STATE_10 && *ch != comp_states[STATE_11]) {
			state = STATE_0;
		}
		/* 11 -> 12 */
		else if(state ==STATE_11 && (*ch == comp_states[STATE_12] || *ch == comp_states[STATE_13]))  {
			if (*ch == comp_states[STATE_12]) {
				state = STATE_12;
			} else {
				state = STATE_13;
			}
			ch++;
			continue;
		} else if(state ==STATE_11 && *ch != comp_states[STATE_12] && *ch != comp_states[STATE_13]) {
			state = STATE_0;
		}

		/* 14 -> 15 */
		else if(state ==STATE_14 && *ch == comp_states[STATE_15]) {
			state = STATE_15;
			ch++;
			continue;
		} else if(state ==STATE_14 && *ch != comp_states[STATE_1]) {
			state = STATE_0;
			ch++;
			continue;
		}


		/* 12 -> 13 */
		else if ((state == STATE_12 || state == STATE_13)&& *ch == '\n') {
			state = STATE_0;
			*tmp++ = '\n';
		} else if ((state == STATE_12 || state == STATE_13)&& *ch != '\n') {
			ch++;
			continue;
		}

		/* 15 -> 16 */
		else if(state ==STATE_15 && *ch == comp_states[STATE_16]) {
			state = STATE_16;
			ch++;
			continue;
		} else if(state ==STATE_15 && *ch != comp_states[STATE_16]) {
			state = STATE_0;
			ch++;
			continue;
		}

		/* 16 -> 17 */
		/* 15 -> 16 */
		else if(state ==STATE_16 && *ch == comp_states[STATE_17]) {
			state = STATE_17;
			ch++;
			continue;
		} else if(state ==STATE_16 && *ch != comp_states[STATE_17]) {
			state = STATE_0;
			ch++;
			continue;
		}

		/* 17 -> 18 */
		else if(state ==STATE_17 && *ch == comp_states[STATE_18]) {
			state = STATE_18;
			ch++;
			continue;
		} else if(state ==STATE_17 && *ch != comp_states[STATE_18]) {
			ch++;
			continue;
		}

		/* 18-> 19 */
		else if(state ==STATE_18 && *ch == comp_states[STATE_19]) {
			state = STATE_19;
			ch++;
			continue;
		} else if(state ==STATE_18 && *ch != comp_states[STATE_19]) {
			state = STATE_17;
			ch++;
			continue;
		}

		/* 19->20 */
		else if(state ==STATE_19 && *ch == comp_states[STATE_20]) {
			state = STATE_0;
			ch++;
			continue;
		} else if(state ==STATE_19 && *ch != comp_states[STATE_20]) {
			state = STATE_17;
			ch++;
			continue;
		}



		else if(state == STATE_2 && *ch == '\n') {
			state = STATE_0;
			*tmp++ = '\n';
			count++;
		} else if(state == STATE_2) {
			state == STATE_2;

			/*״̬3���л�*/
		} else if((state == STATE_3 || state == STATE_4) && *ch == comp_states[STATE_4]) {
			state = STATE_4;
		} else if(state == STATE_3) {
			state = STATE_3;

			/*״̬4���л�*/
		} else if(state == STATE_4 && *ch == '/') {
			state = STATE_0;
		} else if(state == STATE_4) {
			state = STATE_3;

			/*״̬5�л�*/
		} else if(state ==STATE_8 ) {
			state = STATE_7;
			*tmp++ = *ch;
			count++;

		} else if(state == STATE_6) {
			state = STATE_5;
			*tmp++ = *ch;
			count++;
		} else {
			*tmp++ = *ch;
			count++;
		}

		printf("ch=[%c],state=%d, olen:%d *out:[%s]\n", *ch, state, count, *out);

		ch++;
	}

	*olen = count;

	return 0;
}

/* FUNCTION�� ���ټ��һ���Ƿ�����ظ��Ĳ��� */
static int comp_paras_check_repeat_need_todo(const char *in, int ilen) {
	int i, state;
	if (in == NULL || ilen == 0) {
		return 0;
	}

	if (!comp_paras_check_note_need_todo(in, ilen)) {
		return 0;
	}

	for (i = 0; i < ilen; i++ ) {
		state = comp_paras_note_state_hit(in[i]);
		if ( state == STATE_1
				|| state == STATE_5
				|| state == STATE_7
				|| state == STATE_9
				|| state == STATE_10
				|| state == STATE_14) {
			return 1;
		}
	}

	return 0;
}

/* FUNCTION: check have var repeat */
static int comp_paras_check_repeat(const char *in, int ilen, char **out, int *olen) {

	return 0;
}

/* ���ϲ������� Compound parameter engine */
int comp_paras_check(const char *in, int ilen, char **out, int *olen) {

	if (comp_paras_check_note_do(in,  ilen, out, olen) == -1) {
		return -1;
	}

	if (comp_paras_check_repeat(in,  ilen, out, olen) == -1) {
		return -1;
	}

	return 0;
}

int main(int arg,char **argv) {
	char ch;
	int  state    = STATE_0;

	char *in = textFileRead((char *)"./1.txt");
	int ilen = strlen(in);
	char *out = NULL;
	int olen = 0;

	printf("ilen:%d in:[%s]\n", ilen, in);
	printf("========================== IN END ============================\n");


	if (comp_paras_check(in, ilen, &out, &olen) == -1) {
		printf("Error: %s:%d\n", __func__, __LINE__);
		free(in);
		return -1;
	}

	if (in) {
		free(in);
	}

	printf("olen :%d out:[%s]\n", olen, out);

	printf("\n========================== OUT END ============================\n", in);

	if (olen > 0 && out) {
		printf("olen:%d out:[%s]\n]", olen, out);
		free(out);
	}

	return 0;
}

static char* textFileRead(const char* filename) {
	char* text;
	FILE *pf = fopen(filename,"r");
	fseek(pf,0,SEEK_END);
	long lSize = ftell(pf);

	printf("lSize:%d\n", lSize);

	// �������Ҫ���ڴ�free��
	text=(char*)malloc(lSize+1);
	memset(text, 0, lSize+1);

	rewind(pf);
	fread(text,sizeof(char),lSize,pf);

	return text;
}

