// LeetCode Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<unordered_set>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length=0,st=0,en=0,temp_length=0;
        unordered_set<char> us;
        if(s.length()==1)
            return 1;
        while(en<s.length())
        {
            if(us.find(s[en])==us.end())//dont find in set
            {
                temp_length++;
                us.insert(s[en]);
            }
            else//find in set
            {
                temp_length=1;
                us.clear();
                st++;
                en=st;
                us.insert(s[en]);
            }
            if(max_length<temp_length)
                max_length=temp_length;
            en++;
        }
        return max_length;
    }
};