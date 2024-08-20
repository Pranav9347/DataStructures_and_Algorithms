#include<iostream>
using namespace std;

void divide(int*, int*, int, int);
void merge(int*, int*, int, int, int, int);
void view(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return;
}
int main()
{
    int arr[9] = {2,4,7,2,9,4,1,6,0}, n=9;
    int aux[9];
    divide(arr, aux, 0, n-1);
    view(arr, n);
    return 0;
}
void divide(int* A, int* aux, int left, int right)
{
    if(left == right)
        return;
    int mid = (left+right)/2;
    divide(A, aux, left, mid);
    divide(A, aux, mid+1, right);
    merge(A, aux, left, mid, mid+1, right);
}
void merge(int* A, int* aux, int l1, int r1, int l2, int r2)
{
    int L1 = l1, L2 = l2, i=l1;
    while(L1<=r1 && L2<=r2)
    {
        if(A[L1]<=A[L2])
        {
            aux[i] = A[L1];
            L1++;
        }
        else
        {
            aux[i] = A[L2];
            L2++;
        }
        i++;
    }
    while(L1<=r1)
    {
        aux[i] = A[L1];
        i++;
        L1++;
    }
    while(L2<=r2)
    {
        aux[i] = A[L2];
        L2++;
        i++;
    }
    //copy back to original array A:
    for(int j=l1; j<r2+1; j++)
    {
        A[j] = aux[j];
    }
}
//Time Complexity: O(nlogn)
//Space Complexity: External->O(n)
//Stable sorting algo