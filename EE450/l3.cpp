#include <iostream>
#include <fstream>
using namespace std;

class charMatrix {

private:
    char **xtable;
    int xRes, yRes;
public:
    charMatrix(int xR, int yR, char c) {
        xRes=xR;
        yRes=yR;
        xtable=new char *[yRes];
        for (int i=0; i<xRes; i++)
        {
            xtable[i]=new char[xRes];
        }
        // fill
        for(int i=0;i<yRes;i++)
        {
            for (int j=0;j<xRes;j++){
                xtable[i][j]=c;
            }
        }
    }// charMatrix
    ~charMatrix() {
        for (int i=0; i<xRes; i++)
        {
            delete[] xtable[i];
        }
        delete[] xtable;
    }// ~charMatrix()
    void setChar(int x, int y, char c) {
                xtable[y][x] = c;
    }// setChar()
    void prt() {
        for(int i=0;i<yRes;i++)
        {
            for (int j=0;j<xRes;j++){
                cout << xtable[i][j] << " ";
            }// next col
            cout << endl;
        }// next row
    }// prt()
};

int main()
{
    int xR=25, yR=25;
    charMatrix c(xR,yR,' ');
    for(int i=0;i<yR;i++)
        {
            for (int j=0;j<xR;j++){
		if(((i*j)%2)==0){
			if((i+j)<=25){
              		  c.setChar(i,j,'x');
 			}
		}
            }
        }
    c.prt();
    return 0;
}
