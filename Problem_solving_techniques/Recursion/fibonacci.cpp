#include <iostream>
using namespace std;

int fibonacci(int i)
{
    // 2 base cases:
    if(i==1)
        return 0;
    if(i==2)
        return 1;
    else return fibonacci(i-1)+fibonacci(i-2);
}
int main()
{   
    int i;
    cout<<"Enter i: ";
    cin>>i;
    cout<<"The "<<i<<"th fibonacci number is: "<<fibonacci(i)<<endl;

    return 0;
}