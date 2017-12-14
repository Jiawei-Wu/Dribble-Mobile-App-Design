#include <stdio.h>
int main(){
	int a=3;
	int b=2;
	int array[3];
	int *pa=array;
	pa[0]=1;
	pa[1]=10;
	pa[2]=100;

	int *p=&a;
	p+=3;//move the address 3 unites differenite *(p+=3);i
	*p=101;
	p=&a;
	int i;
	for (i=0;i<6;i++){
		printf("*p=%d\n",*p);	
		p++;
	}
	printf("--------------------\n");
	p=&a;
	for (i=0;i<6;i++){
		printf("p[%d]=%d\n",i,p[i]);
	}
}
