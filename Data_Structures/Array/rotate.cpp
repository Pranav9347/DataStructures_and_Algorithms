#include<iostream>
using namespace std;

void print_array(int*, int);
int main()
{   
    int A[] = {1,2,3,4,5};  //initialize all elements to 0
    int n=5;
    //right_rotate:
    int temp = A[n-1];
    for(int i=n-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0]=temp;
    cout<< "Right rotate: ";
    print_array(A,n);

    //left rotate:
    temp=A[0];
    for(int i=0; i<n-1 ;i++)
    {
        A[i]=A[i+1];
    }
    A[n-1]=temp;
    cout<< "\nLeft rotate: ";
    print_array(A,n);
    return 0;
}
void print_array(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return;
}