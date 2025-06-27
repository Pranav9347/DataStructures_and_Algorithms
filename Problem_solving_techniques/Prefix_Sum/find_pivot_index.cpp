// LeetCode Problem: https://leetcode.com/problems/find-pivot-index/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n=nums.size();

    // Determine the prefix and suffix sums
    vector<int> prefix_sum(n), suffix_sum(n);
    prefix_sum[0] = nums[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i] = nums[i] + prefix_sum[i-1];
    }
    suffix_sum[n-1] = nums[n-1];
    for(int i=n-2; i>=0; i--)
    {
        suffix_sum[i] = nums[i] + suffix_sum[i+1];
    }

    // Find common element in both these arrays efficiently(exploit their monotonicity: always increasing(works only is all numbers are +ve))
    // int p=0, s=n-1;
    // while(p+1<s)
    // {
    //     if(prefix_sum[p]<suffix_sum[s])
    //         p++;
    //     else if(prefix_sum[p]>suffix_sum[s])
    //         s--;
    //     else
    //     {
    //         if(s-p==2)
    //             return p+1;
    //         else p++;
    //     }
    // }

    //edge case: left-most index is pivot:
    if(prefix_sum[0]==suffix_sum[0])
        return 0;
            
    for(int p=0;p<n-2;p++)
    {
        if(prefix_sum[p]==suffix_sum[p+2])
            return p+1;
    }
    
    //edge case: right-most index is pivot:
    if(prefix_sum[n-1]==suffix_sum[n-1])
        return n-1;
    return -1;
}

int main()
{
    vector<int> nums={1,7,3,6,5,6};

    cout << pivotIndex(nums);
    return 0;
}