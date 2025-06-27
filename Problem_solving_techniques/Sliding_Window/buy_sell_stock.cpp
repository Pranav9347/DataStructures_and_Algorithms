// LeetCode Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,cur_prof=0;
        int b=0,s=1;
        while(s<prices.size())
        {
            cur_prof=prices[s]-prices[b];
            if(cur_prof<0 && s!=prices.size()-1)
            {
                b=s;
            }
            if (cur_prof>profit)
                profit = cur_prof;
            s++;
        }
        return profit;
    }
};