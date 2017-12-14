#include <iostream>
#include <string>
using namespace std;

typedef struct {
        int id;
        char classif;
        float GPA;
}cool;



int main(){

	cool s1,s2;
	s1.id=12345;
	s1.classif='j';
	s1.GPA=3.8;

	s2.id=13579;
	s2.classif='M';
	s2.GPA=2.98;
	
	cout<<s1.id<<endl;
	cout<<s2.GPA<<endl;
}
