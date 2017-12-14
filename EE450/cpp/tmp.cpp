#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
int main(){
    string name;
    cout<<"Please input your name:";
    cin<<name;
    if(name.empty){
        cout<<"input is null"<<endl;
    }
    if(name == "imooc"){
        cout<<"you are an administrator"<<endl;
    }
    cout<<"hello " + name<<endl;
    cout<<"your name length is:"+name.size()<<endl;
    cout<<"your name first letter is"+name[0]<<endl;
    return 0;
}
