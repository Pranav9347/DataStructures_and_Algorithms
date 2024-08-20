#include<iostream>
using namespace std;

bool binary_search(int* A, int n, int target)
{
    int left = 0, right = n-1, mid = 0;
    while(left<=right)
    {
        mid = left+(right-left)/2;
        if(target == A[mid])
            return true;
        else if(target > A[mid])
            left = mid+1;
        else
            right = mid-1;
    }
    return false;
}
int main()
{
    int arr[10]={0,1,2,4,5,6,7,8,11,16};
    bool x = binary_search(arr,10,11);
    if(x)
        cout<<"Present in array!";
    else cout<<"Not present in array";
    return 0;
}