#include<iostream>
#include<fstream>
using namespace std;
#include <chrono>
using namespace std::chrono;


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
    int arr[100], n = 100;
    int i=0;
    ifstream fin("rand_in.txt",ios::in);
    if(!fin)
    {
        cout<<"Error opening input file!"<<endl;
        return 1;
    }
    else
    {
        while(!fin.eof())
        {
            fin >> arr[i];
            i++;
        }
    }
    auto start = high_resolution_clock::now();
    bubble_sort(arr, n);
    auto stop = high_resolution_clock::now();
    fin.close();
    ofstream fout("sorted_out.txt",ios::trunc);
    if(!fout)
    {
        cout<<"Couldn't open output file!"<<endl;
        return 2;
    }
    else
    {
        for(int i=0; i<100; i++)
        {
            fout << arr[i]<<endl;
        }
    
    }
    fout.close();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms"<< endl;//average 54.4 ms
    return 0;
}