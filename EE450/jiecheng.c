#include<stdio.h>
int func(int n)
{
	int result;
	if(n<0)	
		printf("The data is error");
	else if(n==0||n==1)
		result=1;
	else 
		result=n*func(n-1);
	return result;
}

int main()
{	
	int a;
	int result;
	printf("Please input n\n");
	scanf("%d",&a);
	func(a);
	printf("The result is %d\n",result);
	return 0;
}

