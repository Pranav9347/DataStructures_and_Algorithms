#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void insertion_sort(int* A, int n)
{   
    int j, temp;
    for(int i=1; i<n; i++)
    {
        j=i;
        while(A[j]<A[j-1] && j!=0)
        {
            //swap(A[j],A[j-1]);
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
            j--;
        }
    }
}

int main()
{
    int n=100;
    int* arr = new int[100];
    ifstream fin;
    fin.open("rand_in.txt");
    if(!fin.is_open())
    {
        cout<<"Unable to open input file!"<<endl;
        return 1;
    }
    int i=0;
    while(!fin.eof())
    {
        fin >> arr[i];
        i++;
    }
    fin.close();
    auto start = high_resolution_clock::now();
    insertion_sort(arr, n);
    auto stop = high_resolution_clock::now();

    ofstream fout;
    fout.open("sorted_out1.txt");
    if(!fout.is_open())
    {
        cout<<"Unable to open output file!"<<endl;
        return 2;
    }
    for(int j=0; j<100; j++)
    {
        fout<<arr[j]<<endl;
    }
    fout.close();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " ms"<< endl;//average 25.8 ms
    delete[] arr;
    return 0;
}