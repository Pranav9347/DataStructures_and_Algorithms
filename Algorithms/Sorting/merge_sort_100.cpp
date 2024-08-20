#include<iostream>
#include<chrono>
#include<fstream>

using namespace std;
using namespace std::chrono;


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
void divide(int* A, int* aux, int left, int right)
{
    if(left == right)
        return;
    int mid = (left+right)/2;
    divide(A, aux, left, mid);
    divide(A, aux, mid+1, right);
    merge(A, aux, left, mid, mid+1, right);
}

int main()
{
    int arr[100], aux[100], n=100;
    ifstream fin("rand_in.txt");
    if(!fin)
    {
        cout<<"Error opening input file!"<<endl;
        return 1;
    }
    int i=0;
    while(!fin.eof())
    {
        fin>>arr[i];
        i++;
    }
    fin.close();
    auto start = high_resolution_clock::now();
    divide(arr, aux, 0, n-1);
    auto stop = high_resolution_clock::now();
    ofstream fout("sorted_out2.txt");
    if(!fout)
    {
        cout<<"Error opening output file!"<<endl;
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        fout<<arr[i]<<endl;
    }
    fout.close();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms"<< endl;//average 16.2 ms
    return 0;
}