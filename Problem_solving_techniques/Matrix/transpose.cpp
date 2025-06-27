// LeetCode Problem: https://leetcode.com/problems/transpose-matrix/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpos(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> columns(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            columns[i][j]=grid[j][i];
    return columns;
}

int main()
{
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> transposA = transpos(A);
    for(auto a:transposA)
    {
        for(auto b:a)
            cout <<b<<" ";
        cout<<endl;
    }
    return 0;
}