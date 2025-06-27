// LeetCode Problem: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int p1=0,p2=0,c=0,ans=0;
        while(p2 < nums.size())
        {
            if(nums[p2]<=right && nums[p2]>=left)
            {
                c = p2-p1+1;//number of sub-arrays on including nums[p2]
                ans+=c;
            }
            else if(nums[p2]<left)
            {
                ans+=c;
            }
            else
            {
                p1=p2+1;
                c=0;
            }
            p2++;
        }
        return ans;
    }
};