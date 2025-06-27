// LeetCode Problem: https://leetcode.com/problems/next-permutation/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void swap(vector<int>::iterator i1,vector<int>::iterator i2)
    {
        int temp = *i1;
        *i1 = *i2;
        *i2 = temp;
        return;
    }
    vector<int>::iterator next_bigger(vector<int>::iterator i, vector<int>& nums)
    {
        int diff = 1000;
        vector<int>::iterator p = i+1, nb;
        while(p != nums.end())
        {   
            if(diff > (*p - *i) && (*p - *i) > 0)
            {
                diff = *p - *i;
                nb = p;
            }
            p++;
        }
        return nb;
    }
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator i1 = nums.end()-2, i2 = nums.end()-1, i3;
        if(nums.size() == 1)
            return;
        while(1)
        {
            if(i1 == nums.begin() && *i2 <= *i1)
            {
                sort(nums.begin(),nums.end());
                return;
            }
            if(*i2 > *i1 && i2 == nums.end())
            {
                swap(i1,i2);
                return;
            }
            if(*i2 > *i1)//ascending order
            {
                i3 = next_bigger(i1, nums);
                swap(i1,i3);
                sort(i1+1, nums.end());
                return;
            }
            else
            {
                i1--;
                i2--;
            }
        }
        
    }
};

int main()
{
    Solution S;
    vector<int> v = {1,2,3,4};
    S.nextPermutation(v);
    for(int x: v)
        cout << x <<" ";
    return 0;
}