#include <iostream>
#include <vector>
#include <string>
using namespace std;

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
// [1,12,-5,-6,50,3]
// k=4
// 12.75000

int main()
{
    int n = 6, k =4, i=0,j=0, temp_sum=0, max_sum = INT_MIN;
    float avg;
    vector<int> nums = {1,12,-5,-6,50,3};
    while(j<nums.size())
    {
        temp_sum+= nums[j];
        j++;
        if(k == j-i)
        {
            if(max_sum < temp_sum)
                max_sum = temp_sum;
            temp_sum -= nums[i];
            i++;
        }

    }
    avg = (float)max_sum/(float)k;
    cout<< avg;
    return 0;
}