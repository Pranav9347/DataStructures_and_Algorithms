// LeetCode Problem: https://leetcode.com/problems/max-consecutive-ones-iii/

#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int i=0,j=0,curr=0,max=0,temp_k=k;
    while(j<nums.size())
    {
        if(nums[j]==0 && temp_k>0)
        {
            curr++;
            temp_k--;
        }
        else if(nums[j]==1)
        {
            curr++;
        }
        else
        {
            curr=0;
            temp_k=k;
            i++;
            j=i;
            continue;
        }
        if(curr>max)
            max = curr;
        j++;
    }
    return max;
}

int main()
{
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=3;
    cout <<longestOnes(nums,k);

    return 0;
}

/* 'Sliding window' with variable window size: Whenever the word 'conescutive' comes*/