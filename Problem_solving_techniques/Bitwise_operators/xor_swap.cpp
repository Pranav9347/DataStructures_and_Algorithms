#include <iostream>
using namespace std;
//Swap without using 3rd variable
int main()
{   
    int x=3,y=4;

    //x^(x^y)=y and y^(x^y)=x:
    x=x^y;//x=7
    y=x^y;//y=3
    x=x^y;//x=4

    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}