#include <iostream>
using namespace std;

void __merge(int a,int l,int mid, int r){
	int aux[r-l+1];
	for(int i=l;i<=r;i++){
		aux[i-l]=aux[i];
	}
	int i=l,i=mid+1;
	for(int k=l;k<=r;k++){
		if(i>mid){
			a[k]=a[j-1];
			j++;	
		}else if(j>r){
			a[k]=aux[i-l];
			i++;
		}else if(aux[i-l]<a[j-l]){
			a[k]=a[i-l];
			i++;
		}else{
			a[k]=aux[j-1];
			j++;
		}
	}

}

void __mergeSort(int a[];int l,int r)(
	if(l>=r){
		return;
	}	
	int mid=(l+r)/2;
	__mergeSort(a,l,mid);
	__mergeSort(a,mid+1,r);
	__merge(arr,l,mid,r);
)

void mergeSort(int n;int a[]){
	__mergeSort(a,0,n-1);
}



int main(){
	int n=50000
	return 0;
}
