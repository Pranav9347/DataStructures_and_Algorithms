#include<iostream>
using namespace std;
void view(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort(int* A, int n)
{   
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int main()
{
    int arr[10] = {3,1,5,6,2,4,0,9,7,5}, n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    view(arr,n);
    bubble_sort(arr, n);
    cout<<"After sorting: ";
    view(arr, n);
    return 0;
}
//Time Complexity: O(n^2)
//Space Complexity: Inplace->O(1)