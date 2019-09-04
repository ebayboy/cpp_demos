/* rand.c */
/* 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int i, j;
	
	srand((unsigned)time(NULL));
	
	for (j = 0; j < 10; j++) {
		i = rand();
		printf("rand %d = %d\n", j, i);
	}
	
	return 0;
}
*/

/* rand.cpp */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int i,j;
	
	srand((unsigned)time(NULL));
	
	for (i = 0; i < 10; i++) {
		j = rand();
		cout << "rand number:" << j << endl;
	}
	
	return 0;
}
