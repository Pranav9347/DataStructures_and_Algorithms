#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

int main()
{
    srand(time(0));
    ofstream fout("rand_in.txt");
    if(fout)
    {
        for(int i=0; i<100; i++)
        {
            fout << rand()%200-100 <<endl;
        } 
    }
    fout.close();
    return 0;
}