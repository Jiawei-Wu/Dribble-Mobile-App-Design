#include <iostream>

using namespace std;

struct complex{
	private:
		double i,r;

	public:
		complex(double real,double imag){
		i=imag;
		r=real;
		}	
	
	
	void add(complex a){
		i+=a.i;
		r+=a.r;
	}
	void multiply(complex a){
		r=(r*a.r)-(i*a.i);
		i=(r*a.i)+(i*a.r);	
	}
	void conjugate(complex a){
		i=-i;
	}
	void print(){
		char sign = (i<0)?'-':'+';
		cout<<r<<" "<<sign<<" "<<(i>0?i:-i)<<'i'<<endl;
	}
};

int main(){
	complex x=(3,4),y=(1,-0.25);
	x.print();
	y.print();

	x.add(y);
	x.print();

	y.multiply(x);
	y.print();

	x.conjugate();
	x.print();

	y.conjugate();
	y.print();
	return 0;
}
