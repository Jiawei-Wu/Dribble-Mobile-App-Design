#include <iostream>
#include <string>
using namespace std;

int main(){
	float **xtable;
	cout<<xtable<<endl;

	float *xtable[12];
	//xtable=new float*[12];
	cout<<xtable<<endl;

	for(int i=0;i<12;i++){
		xtable[i]=new float[24];
	}

	for(int i=0;i<12;i++){
		for(int j=0;j<24;j++){
			xtable[i][j]=45;
		}
	}

	for(int i=0;i<12;i++){
		for(int j=0;j<24;j++){
			cout<<xtable[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
