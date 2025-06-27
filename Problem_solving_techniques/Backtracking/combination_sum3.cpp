// Leetcode: https://leetcode.com/problems/combination-sum-iii/
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    int sum=0;
    void comb_gen(int start, int i, int k, int n, vector<int> temp)
    {
        if(temp.size() == k)
        {
            for(int num:temp)
                sum+=num;
            if(sum == n)
                res.push_back(temp);
            sum=0;
            return;
        }
        for(int j=start;j<10;j++)
        {
            temp.push_back(j);
            comb_gen(j+1, i+1, k, n, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        comb_gen(1, 0, k, n, vector<int>());
        return res;
    }
};