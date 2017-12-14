#include <iostream>
#include <algorithm>


using namespace std;

void selectionSort(int n,int a[]){
        for(int i=0;i<n;i++){
                int minIndex=i;
                for (int j=0;j<n;j++){
                        if(a[minIndex]>a[j]){
                                minIndex=j;
                                swap(a[i],a[minIndex]);
                        }
                }
        }
}

int main(){
        int a[10]={10,9,8,7,6,5,4,3,2,1};
        selectionSort(10,a);
        for (int i=0;i<10;i++){
                cout<<a[i]<<" ";
        }
	cout<<endl;
	return 0;
}







