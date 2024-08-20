#include<iostream>
using namespace std;
int main()
{
    //XOR operator
    int x=3,y=4,z=0;
    z=x^y;
    cout<<z;

    //Bitwise AND operator
    z=x&y;
    cout<<z;

    //Bitwise OR operator
    z=x|y;
    cout<<z;

    //Bitwise NOT operator
    z=~x;
    cout<<z;

    //Left-shift operator
    z=x<<1;
    cout<<z;

    //Right-shift operator
    z=x>>1;
    cout<<z;
    return 0;
}