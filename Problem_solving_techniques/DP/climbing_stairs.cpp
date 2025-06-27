// Leetcode: https://leetcode.com/problems/min-cost-climbing-stairs/
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // build min_cost table backwards
        // record min cost to reach goal from index i: DP[i]
        vector<int> DP(n);
        DP[n-1] = cost[n-1], DP[n-2] = cost[n-2];
        for(int i=n-3;i>=0;i--)
        {
            DP[i] = min((cost[i]+DP[i+1]),(cost[i]+DP[i+2]));
        }
        return min(DP[0],DP[1]);
    }
};