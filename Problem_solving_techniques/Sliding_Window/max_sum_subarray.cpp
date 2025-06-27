// LeetCode Problem: https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int i=0, j=0, max_sum=0, new_sum=0;
    while(j<=k-1)
    {
        max_sum += nums[j];
        j++;
    }
    new_sum=max_sum;
    while(j<nums.size())
    {
        new_sum += nums[j];
        new_sum -= nums[i];
        if(max_sum < new_sum)
            max_sum = new_sum;
        j++;
        i++;
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    cout <<findMaxAverage(nums,4);

    return 0;
}