#include <iostream>
#include <fstream>
using namespace std;

class array2D{
	protected:
		float **xtable;
		int xRes,yRes;
	public:
		array2D(int xR, int yR){
			xRes=xR;
			yRes=yR;
			xtable = new float *[yRes];
			for(int i=0;i<yRes;i++){
				xtable[i]=new float[xRes];
			}
			for(int i=0;i<yRes;i++){
				for(int j=0;j<xRes;j++){
					xtable[i][j]=0;	
				}
			}
		}//constructor
		~array2D(){
			for(int i=0;i<yRes;i++){
				delete[] xtable[i];
			}
			delete[] xtable;
		}//destructor
		void getSize(int &xR,int &yR){
			xR=xRes;
			yR=yRes;
		}//getsize
		void setValue(int x,int y,int value){
		//	for(int i=0;i<xRes;i++){
			//	for(int j=0;j<yRes;j++){
					xtable[x][y]=value;
			//	}	
			//}
		}
		int getValue(int x,int y){
			return xtable[x][y];
		}

};

int main(){
	array2D *a=new array2D(320,240);
	int xRes,yRes;
	a->getSize(xRes,yRes);
	for(int i=0;i<yRes;i++){
		for(int j=0;j<xRes;j++){
			a->setValue(i,j,100);
		}
	}//Fill
	for(int i=0;i<yRes;i++){
		for(int j=0;j<xRes;j++){
			cout<<a->getValue(i,j)<<" ";
		}
		cout<<endl;
	}//Output
	return 0;
}
