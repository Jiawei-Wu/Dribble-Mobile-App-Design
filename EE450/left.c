#include<stdio.h>
int main(){
	int a=3;//0000 0011
	int i=1;
	i=i<<2;
	a=a<<4;//0011 0000
	printf("i=%d\na=%d\n",a,i);
	return 0;
}
