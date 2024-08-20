#include<iostream>
using namespace std;
int digits(int n)
{
    if(n == 0)
        return 0;
    else return digits(n/10)+1;
}

int main()
{   
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"It has "<<digits(n)<<" digit(s)"<<endl;
    return 0;
}