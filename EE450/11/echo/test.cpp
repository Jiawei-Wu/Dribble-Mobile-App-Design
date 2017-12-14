#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
string line;
string data[100];
ifstream myfile;
myfile.open("job.txt");
int i = 0;
while (!myfile.eof())
{
myfile >> data[i];
++i;

}
i = 0;
while (!data[i].empty())
{
cout << data[i] << endl;
i++;
}

}
