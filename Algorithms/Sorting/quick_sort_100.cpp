#include<iostream>
#include<chrono>
#include<fstream>

using namespace std;
using namespace std::chrono;

int partition(int* A, int left, int right)
{
    //pivot at right
    int p = right, temp;
    while(left != right)
    {
        if(p == right && A[left]>A[p])
        {
            temp = A[left];
            A[left] = A[p];
            A[p] = temp;
            right--;
            p = left;
        }
        else if(p == right && A[left]<=A[p])
        {
            left++;
        }
        else if(p == left && A[right]<A[p])
        {
            temp = A[right];
            A[right] = A[p];
            A[p] = temp;
            left++;
            p = right;
        }
        else if(p == left && A[right]>=A[p])
        {
            right--;
        }
    }
    return p;
}
void divide(int* A, int left, int right)
{
    if(left >= right)
        return;
    int p = partition(A, left, right);
    divide(A, left, p-1);
    divide(A, p+1, right); 
}
//Time Complexity: O(nlogn)
//Space Complexity: Inplace-O(1)
//Not a stable sorting algo

int main()
{
    int arr[100], n=100;
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
    divide(arr, 0, n-1);
    auto stop = high_resolution_clock::now();
    ofstream fout("sorted_out3.txt");
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
    cout << duration.count() << " ms"<< endl;//average 11 ms
    return 0;
}