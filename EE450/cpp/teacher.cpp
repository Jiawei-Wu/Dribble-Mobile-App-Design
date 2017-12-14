#include "teacher.h"
#include <iostream>

using namespace std;

void teacher::setName(string _name){
	name=_name;
}
string teacher::getName(){
        return name;
}
void teacher::setGender(string _gender){
        gender=_gender;
}
string teacher::getGender(){
        return gender;
}
void teacher::setAge(int _age){
        age=_age;
}
int teacher::getAge(){
        return age;
}
void teacher::teach(){
        cout<<"on class"<<endl;
}

