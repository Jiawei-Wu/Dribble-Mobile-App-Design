#include<stdio.h>
int main()
{
	int a=9;//0000 1001
	int b=5;//0000 0101
		//0000 1100
	int c=a^b;
	printf("c=%d\n",c);
	a=a^0xff;
	printf("a=%d\n",a);
	return 0;
}
