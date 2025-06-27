// Leetcode: https://leetcode.com/problems/house-robber/
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n);
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        DP[n-1] = nums[n-1], DP[n-2] = nums[n-2], DP[n-3] = nums[n-3]+nums[n-1];
        if(n == 3) return max(DP[0],nums[1]);
        for(int i=n-4;i>=0;i--)
        {
            DP[i] = max((nums[i]+DP[i+2]),(nums[i]+DP[i+3]));
        }
        return max(DP[0],DP[1]);
    }
};