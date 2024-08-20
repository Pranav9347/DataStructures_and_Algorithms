#include <iostream>
#define max_size 100
using namespace std;

int main()
{
    int A[max_size] = {0};  //initialize all elements to 0
    int n, index;
    //user input:
    cout<< "Enter n: ";
    cin>>n;
    cout<< "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<< "Enter the index of element to be deleted: ";
    cin>> index;

    //deletion:
    for(int i=index; i<n-1;i++)
    {
        A[i] = A[i+1];
    }
    n--;    //decrement array size

    //output:
    for(int i=0; i<n; i++)
    {
        cout<< A[i]<<" ";
    }
    return 0;
}