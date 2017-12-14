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
			xtable[x][y]=value;
		}
		int getValue(int x,int y){
			return xtable[x][y];
		}

};

class PGMImage:public array2D{
	private:
		char filename[2048];
	public:
		PGMImage(int xR,int yR,char imageFilename[2048]){
			xRes=xR;
			yRes=yR;
			filename[2048]=imageFilename[2048];
		}
		void getResolution(int &xR,int &yR){
			xR=xRes;
			yR=yRes;
		}
		void setPixel(int x,int y,int val){
			xtable[x][y]=val;
		}
		int getPixel(int x,int y){
			return xtable[x][y];
		}
		void writeFile(){
			ofstream pgmFile("myImg.pgm");
			pgmFile <<"p2"<<endl;
			pgmFile <<xRes<<" "<<yRes<<endl;
			pgmFile <<255<<endl;
			for(int i=0;i<yRes;i++){
				for(int j=0;j<xRes;j++){
					pgmFile<<xtable[i][j]<<" ";
				}
				pgmFile<<endl;
			}
			pgmFile.close();			
		}
};

int main(){
	PGMImage *a=new PGMImage(320,240,"pic");
	int xRes,yRes;
	a->getResolution(xRes,yRes);
	for(int i=0;i<yRes;i++){
		for(int j=0;j<xRes;j++){
			a->setPixel(i,j,100);
		}
	}
	for(int i=0;i<yRes;i++){
		for(int j=0;j<xRes;j++){
			cout<<a->getPixel(i,j)<<" ";
		}
		cout<<endl;
	} 
	a->writeFile();
}
