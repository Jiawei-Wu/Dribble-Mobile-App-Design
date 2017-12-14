#include<stdio.h>
struct weapon{
	char name[20];
	int atk;
	int price;
};

int main()
{
	int a=0;
	float b=0.0;
	
	struct weapon weapon_1={"weapon_name",100,200 };
	printf("%s\n%d\n",weapon_1.name,++weapon_1.price);	
	struct weapon *w;
	w=&weapon_1;
	printf("name=%s\n,name=%s\n",(*w).name,w->name);//w->name


	struct weapon weapon_2[2]={{"weapon_name1",50,100},{"weapon_name2",100,200}};
	printf("%s\n%d\n",weapon_2[0].name,weapon_2[1].atk);
	
	struct weapon *p;
	p=weapon_2;//p->name weapon_2[0].name
	printf("%s\n",p->name);
	p++;//weapon_2+1 weapon_2[1]
	printf("%s\n",p->name);


	return 0;
}
