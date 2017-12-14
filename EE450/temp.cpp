#include <iostream>
#include <string>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main(){
	int a=5;
	int b=8;
	swap(a,b);
	cout<<a<<","<<b<<endl;
}
