#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

void divide(int*, int, int);
int partition(int*, int, int);
void view(int* A, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int arr[] = {2, 4, 3, 7, 1, -2, 6, 9, 11, -7}, n = 10;
    auto start = high_resolution_clock::now();
    divide(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    view(arr, n);
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms"<< endl;
    return 0;
}

void divide(int* A, int left, int right)
{
    if(left >= right)
        return;
    int p = partition(A, left, right);
    divide(A, left, p - 1);
    divide(A, p + 1, right); 
}

int partition(int* A, int left, int right)
{
    int pivot = A[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[right]);
    return i + 1;
}
