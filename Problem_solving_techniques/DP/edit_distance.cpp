// Leetcode: https://leetcode.com/problems/edit-distance/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> DP(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++)
            DP[i][0] = i;
        for(int j=0;j<m+1;j++)
            DP[0][j] = j;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    DP[i][j] = DP[i-1][j-1];
                }
                else
                {
                    DP[i][j] = min({DP[i][j-1],DP[i-1][j],DP[i-1][j-1]})+1;
                }
            }
        }
        return DP[n][m];
    }
};