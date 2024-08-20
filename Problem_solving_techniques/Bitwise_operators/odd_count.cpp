#include<iostream>
using namespace std;
int main()
{
    int res=0;
    int arr[11]={2,2,3,3,4,3,4,2,5,2,5};//011^010
    for(int i=0;i<11;i++)
    {
        res^=arr[i];
    }
    cout<<res<<endl;
    return 0;
}