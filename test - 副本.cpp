/* c����ʵ��ȥ�������е�ע�� */

/* ԭ��ƥ��һ�飬���δ���� :
 * ���ٹ�������ƥ�䴮�Ƿ����ע���ַ������е��ַ��� ���û������з���
 * �������ȥ��ע�ͺ���ƥ��һ��
 * */
 
 #include <stdio.h>
 #include <string.h>

/* COMMON Code Note, include MYSQL/XSS/C/XSCript ... */
#define STATE_0  0  /*����״̬*/
#define STATE_1  1  /* /  */
#define STATE_2  2  /* //  */
#define STATE_3  3  /* /*  */
#define STATE_4  4  /* /** */
#define STATE_5  5  /* '  */
#define STATE_6  6  /* ��\  */
#define STATE_7  7  /* "  */
#define STATE_8  8  /* "\  */

//=================== BELLOW ===================

/* XSS Code Note  */
#define STATE_9  9   /* \\ */
#define STATE_10  10  /* \\ */

/* MYSQL Code Note */
#define STATE_11  11  /* # */
#define STATE_12  12  /* -- */


int main(int arg,char **argv) {
	FILE *fp=fopen("./test.log","r+w");

	char *str1 = "/* afdasdf */";
	char *str2 = "// afdasdf */";
	char *str3 = "/* afdasdf ";
	char *str4 = "afdasdf */";
	
	char ch;
	int  state    = STATE_0;
	char buf[4096] = {0};
	char *tmp = buf;

	while((ch = fgetc(fp)) != EOF) {
		// ch = *p;
		// while(ch!='\0'){
		//ch = *p++;
		
		/*״̬0��״̬�л�*/ 
		if(state==STATE_0 && ch=='/') {
			state = STATE_1;
		} else if(state ==STATE_0 && ch=='\'') {
			state = STATE_5;
			*tmp++ = ch;
		} else if(state ==STATE_0 && ch=='\"') {
			state = STATE_7;
			*tmp++ = ch;
		} else if(state==STATE_0) {
			state = STATE_0;
			*tmp++ = ch;

		/*״̬1��״̬�л�*/
		} else if(state==STATE_1 && ch=='/') {
			state = STATE_2;
		} else if(state==STATE_1 && ch=='*') {
			state = STATE_3;
		} else if(state==STATE_1) {
			state = STATE_0;
			*tmp++ = '/';   /* ���� 5/3 ����� */
			*tmp++ = ch;

		/*״̬2���л�*/
		} else if(state == STATE_2 && ch == '\n') {
			state = STATE_0;
			*tmp++ = '\n';
		} else if(state == STATE_2) {
			state == STATE_2;

		/*״̬3���л�*/
		} else if(state == STATE_3 && ch == '*') {
			state = STATE_4;
		} else if(state == STATE_3) {
			state = STATE_3;

		/*״̬4���л�*/
		} else if(state == STATE_4 && ch == '/') {
			state = STATE_0;
		} else if(state == STATE_4) {
			state = STATE_3;

		/*״̬5�л�*/
		} else if(state == STATE_5 && ch == '\\') {
			state = STATE_6;
			*tmp++ = ch;
		} else if(state == STATE_5 && ch == '\'') {
			state = STATE_0;
			*tmp++ = ch;
		} else if(state == STATE_5) {
			state = STATE_5;
			*tmp++ = ch;

		/*״̬6�л�*/
		} else if(state == STATE_6) {
			state = STATE_5;
			*tmp++ = ch;

		/*״̬7���л�*/
		} else if(state == STATE_7 && ch =='\\') {
			state = STATE_8;
			*tmp++ = ch;
		} else if(state == STATE_7 && ch =='\"') {
			state = STATE_0;
			*tmp++ = ch;
		} else if(state == STATE_7) {
			state = STATE_7;
			*tmp++ = ch;

		/*״̬8���л�*/
		} else if(state ==STATE_8 ) {
			state = STATE_7;
			*tmp++ = ch;
		}
		//printf("ch=%c,state=%d\n",ch,state);
	}

	*tmp = '\0';
	printf("%s\n",buf);

	return 0;
}
