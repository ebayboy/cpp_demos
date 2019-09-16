/* c语言实现去除代码中的注释 */

/* 原文匹配一遍，如果未命中 :
 * 快速过滤整个匹配串是否包含注释字符数组中的字符， 如果没有则进行放行
 * 如果有则去掉注释后再匹配一遍
 * */
 
 #include <stdio.h>
 #include <string.h>

/* COMMON Code Note, include MYSQL/XSS/C/XSCript ... */
#define STATE_0  0  /*正常状态*/
#define STATE_1  1  /* /  */
#define STATE_2  2  /* //  */
#define STATE_3  3  /* /*  */
#define STATE_4  4  /* /** */
#define STATE_5  5  /* '  */
#define STATE_6  6  /* ·\  */
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
		
		/*状态0的状态切换*/ 
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

		/*状态1的状态切换*/
		} else if(state==STATE_1 && ch=='/') {
			state = STATE_2;
		} else if(state==STATE_1 && ch=='*') {
			state = STATE_3;
		} else if(state==STATE_1) {
			state = STATE_0;
			*tmp++ = '/';   /* 比如 5/3 的情况 */
			*tmp++ = ch;

		/*状态2的切换*/
		} else if(state == STATE_2 && ch == '\n') {
			state = STATE_0;
			*tmp++ = '\n';
		} else if(state == STATE_2) {
			state == STATE_2;

		/*状态3的切换*/
		} else if(state == STATE_3 && ch == '*') {
			state = STATE_4;
		} else if(state == STATE_3) {
			state = STATE_3;

		/*状态4的切换*/
		} else if(state == STATE_4 && ch == '/') {
			state = STATE_0;
		} else if(state == STATE_4) {
			state = STATE_3;

		/*状态5切换*/
		} else if(state == STATE_5 && ch == '\\') {
			state = STATE_6;
			*tmp++ = ch;
		} else if(state == STATE_5 && ch == '\'') {
			state = STATE_0;
			*tmp++ = ch;
		} else if(state == STATE_5) {
			state = STATE_5;
			*tmp++ = ch;

		/*状态6切换*/
		} else if(state == STATE_6) {
			state = STATE_5;
			*tmp++ = ch;

		/*状态7的切换*/
		} else if(state == STATE_7 && ch =='\\') {
			state = STATE_8;
			*tmp++ = ch;
		} else if(state == STATE_7 && ch =='\"') {
			state = STATE_0;
			*tmp++ = ch;
		} else if(state == STATE_7) {
			state = STATE_7;
			*tmp++ = ch;

		/*状态8的切换*/
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
