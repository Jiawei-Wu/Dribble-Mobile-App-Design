#include<stdio.h>
/*
struct data{
	int a;
	char b;
	int c;
};//in this case, the memory is the sum of all valuables
*/


union data{
	int a;
	char b;
	int c;
};//using the same memory


int main()
{
	union data data_1;//only one constant;
	data_1.b='C';
	data_1.a=10;
	printf("The value of b is %d\nThe value of a is %d\n",data_1.b,data_1.a);
	printf("%p\n%p\n%p\n",&data_1.a,&data_1.b,&data_1.c);
}
