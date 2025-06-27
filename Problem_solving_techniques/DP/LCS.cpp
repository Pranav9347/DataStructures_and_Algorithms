// Leetcode: https://leetcode.com/problems/longest-common-subsequence/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        vector<vector<int>> DP(m,vector<int>(n,0));
        DP[0][0] = (int)(text1[0]==text2[0]);
        for(int i=1;i<m;i++)
            DP[i][0] = max(DP[i-1][0],(int)(text1[i]==text2[0]));
        for(int j=1;j<n;j++)
            DP[0][j] = max(DP[0][j-1],(int)(text1[0]==text2[j]));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(text1[i] == text2[j])
                    DP[i][j] = DP[i-1][j-1]+1;
                else
                    DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
        return DP[m-1][n-1];
    }
};