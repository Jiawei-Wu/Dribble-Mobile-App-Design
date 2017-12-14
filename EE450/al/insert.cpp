#include <iostream>
#include <algorithm>
using namespace std;

int insert(int a[],int n){
	for (int i=1;i<n;i++){
		for (int j=i;i>0;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}else{
				break;
			}
		}
	}
	return a[n];
}

int main(){
	int a[3]={8,5,6};
	int b[];
	b[]=insert(a,3);
	for(int i=0;i<3;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	return 0;
}
