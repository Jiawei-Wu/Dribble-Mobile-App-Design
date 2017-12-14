#include<iostream>
#include<cmath>
using namespace std;

double AM(double a,double b){
	return (a+b)/2.0;
}

double GM(double a,double b){
	return sqrt(a*b);
}

double HM(double a,double b){
	return 2.0/(1.0/a+1.0/b);
}

double mean(double a,double b,int meanType=0){
	if(meanType==0){
		return AM(a,b);
	}else if(meanType==1){
		return GM(a,b);
	}else{
		return HM(a,b);
	}
};
int main(){
	cout<<"AM:"<<mean(3,5)<<endl;
	cout<<"GM:"<<mean(3,5,1)<<endl;
	cout<<"HM:"<<mean(3,5,2)<<endl;
	return 0;
}
