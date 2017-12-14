#include<stdio.h>
int main()
{
	int a=9;//00000000 00000000 00000000 00001001
	int b=5;//00000000 00000000 00000000 00000101
		//00000000 00000000 00000000 00001101
	int c=a|b;
	printf("c=%d\n",c);
	a=a|0xFF;
	printf("a=%d\n",a);
	return 0;
}
