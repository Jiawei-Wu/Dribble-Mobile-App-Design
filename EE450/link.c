#include<stdio.h>

struct weapon{
	int price;
	int atk;
	struct weapon *next;	
};


int main()
{
	struct weapon a,b,c,*head;
	a.price =100;
	a.atk=100;
	b.price=200;
	b.atk=200;
	c.price=300;
	c.atk=300;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	struct weapon *p;
	p=head;
	while(p!=NULL){
		printf("%d,%d\n",p->atk,p->price);
		p=p->next;
	}
	return 0;
}
