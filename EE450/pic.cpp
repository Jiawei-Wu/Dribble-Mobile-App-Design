#include<iostream>
#include<fstream>

using namespace std;

int main(){
	int xRes=256;
	int yRes=256;

	float **xtable;
	xtable=new float*[yRes];

	for(int i=0;i<yRes;i++){
		xtable[i]=new float[xRes];
	}

	for(int i=0;i<yRes;i++){
		for (int j=0;j<xRes;j++){
			xtable[i][j]=0;
		}
	}

	for (int i=0;i<yRes;i++){
		for (int j=0;j<xRes;j++){
			if ((int)(j/32)%2==0){
					if ((int)(i/32)%2==0){
						xtable[i][j]=255;
					}
	        	}else{
					if ((int)(i/32)%2==1){
						xtable[i][j]=255;
					}
			}
		}	
	}

	ofstream pgmFile("myImg.pgm");

	pgmFile  <<"P2"<<endl;
	pgmFile  <<xRes<<" "<<yRes<<endl;
	pgmFile  <<255<<endl;

	for(int i=0;i<yRes;i++){
		for (int j=0;j<xRes;j++){
			pgmFile<<xtable[i][j]<<" ";
		}
		pgmFile<<endl;
	}
	pgmFile.close();
	return 0;
}


