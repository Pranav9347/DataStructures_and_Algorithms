#include<iostream>
using namespace std;

void print_array(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return;
}
int main()
{   
    int A[] = {5,6,1,2,6};  //initialize all elements to 0
    int n=5,temp;
    for(int i=0; i<n/2; i++)
    {
        //swap(A[i],A[n-1-i])
        temp = A[i];
        A[i] = A[n-1-i];
        A[n-1-i] = temp;
    }
    print_array(A,n);
    return 0;
}