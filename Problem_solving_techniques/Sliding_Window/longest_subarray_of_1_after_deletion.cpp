// LeetCode Problem: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int left=0, right=0, zero_count=0, one_count=0, max_ones=0;
    while(right<nums.size())
    {
        if(nums[right]==1)
            one_count++;
        else if(nums[right]==0 && zero_count==1)
        {
            if(max_ones<one_count)
                max_ones=one_count;
            zero_count=0;
            one_count=0;
            right=left-1;
        }
        else
        {
            zero_count++;
            left=right+1;
        }
        right++;
    }
    if(max_ones<one_count)
        max_ones=one_count;
    if(one_count==nums.size())
        return one_count-1;
    return max_ones;
}

int main()
{

    vector<int> nums = {1,1,0,1,1,1,0,1,1,1,0,1};
    cout << longestSubarray(nums);
    return 0;
}