// Leetcode: https://leetcode.com/problems/unique-paths/
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        vector<vector<int>> DP(m,vector<int>(n,0));
        for(int i=1;i<n;i++)
            DP[0][i] = 1;
        for(int i=1;i<m;i++)
            DP[i][0] = 1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                DP[i][j] = DP[i][j-1]+DP[i-1][j];
            }
        }
        return DP[m-1][n-1];
    }
};