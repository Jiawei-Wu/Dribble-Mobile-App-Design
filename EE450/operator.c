#include<stdio.h>
int main()
{
	int a=4;//00000000 00000000 00000000 00000100
	int b=7;//00000000 00000000 00000000 00000111
		//00000000 00000000 00000000 00000100
	int c=a&b;
	printf("The outcome is %d\n",c);
	return 0;
}
