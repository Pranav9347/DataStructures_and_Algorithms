// LeetCode Problem: https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size()-1, max_area = 0;
        vector<int>::iterator i1 = height.begin(), i2 = height.end()-1;
        while(i1!=i2)
        {
            if(max_area < (width*min(*i1,*i2)))
                max_area = width*min(*i1,*i2);
            if(*i1<*i2)
            {
                i1++;
            }
            else i2--;
            width--;
        }
        return max_area;
    }   
};