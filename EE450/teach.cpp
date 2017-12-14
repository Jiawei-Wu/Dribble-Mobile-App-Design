#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int xRes=512, yRes=256;

    float **xtable; // pointer to pointer[s]
    xtable = new float*[yRes]; // NOTE how we do this!

    for(int i=0;i<yRes;i++) {
      xtable[i] = new float[xRes]; // each row points to xRes elements ("columns")
    }

    for(int i=0;i<yRes;i++){
       for(int j=0;j<xRes;j++){
           xtable[i][j]=45; // store 45 for pixel data, "for now"
       }
    }

    ofstream pgmFile("myImg.pgm"); // output image file we're creating

    // header
    pgmFile << "P2" << endl;
    pgmFile << xRes << " " << yRes << endl; // how many columns, how many rows
    pgmFile << 255 << endl; // largest pixel value we'll be outputting (below)

    // pixel data
    for(int i=0;i<yRes;i++){
        for(int j=0;j<xRes;j++){
            pgmFile << xtable[i][j] << " ";
        }// next column
        pgmFile << endl;
    }// next row

    // all done!
    pgmFile.close();
    return 0;
}// main()
