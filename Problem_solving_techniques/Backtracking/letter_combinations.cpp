// Leetcode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    string arr[9] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void comb_gen(string digits, string comb, int i)
    {
        if(digits.size() == i)
        {
            res.push_back(comb);
            return;
        }
        for(char c: arr[digits[i]-'2'])
        {
            comb_gen(digits, comb+c, i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        string comb="";
        comb_gen(digits, comb, 0);
        return res;
    }
};