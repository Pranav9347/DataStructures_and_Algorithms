// Leetcode: https://leetcode.com/problems/koko-eating-bananas/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //O(n)*log(k) algorithm: binary search on k:
        int max_k = *max_element(piles.begin(),piles.end()), temp_h=0;
        int l = 1, r = max_k, k = l+(r-l)/2;
        while(l<r)
        {
            for(int pile: piles)
            {
                temp_h+=(pile+k-1)/k;
            }
            if(temp_h <= h)
                r = k;
            else if(temp_h > h)
                l = k+1;
            k = l+(r-l)/2;
            temp_h = 0;
        }
        return k;
    }
};