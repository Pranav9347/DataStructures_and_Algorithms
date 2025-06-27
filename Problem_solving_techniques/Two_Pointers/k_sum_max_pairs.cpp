// LeetCode Problem: https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    vector<int>::iterator i=nums.begin(), j=nums.end()-1;
    sort(nums.begin(),nums.end());
    int pairs=0;
    while(i<j)
    {
        if(*i + *j < k)
            i++;
        else if(*i + *j > k)
            j--;
        else
        {
            pairs++;
            nums.erase(i);
            j--;
            nums.erase(j);
            j--;
        }
    }
    return pairs;
}

int main()
{
    vector<int> v = {3,1,3,4,3};
    cout << maxOperations(v,6);
    return 0;
}