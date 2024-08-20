#include<unordered_map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        vector<string> v;
        string t;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ' ')
                t+=s[i];
            else
            {
                v.push_back(t);
                t.clear();
            } 
        }
        v.push_back(t);
        if(v.size()!=pattern.length())
            return false;
        for(int i=0; i<pattern.length(); i++)
        {
            if(m1.find(pattern[i]) == m1.end())
                m1[pattern[i]] = v[i];
            else if(m1[pattern[i]] == v[i])
                continue;
            else return false;

        }
        for(int i=0; i<v.size(); i++)
        {
            if(m2.find(v[i]) == m2.end())
                m2[v[i]] = pattern[i];
            else if(m2[v[i]] == pattern[i])
                continue;
            else return false;

        }
        return true;
    }
};

int main()
{
    Solution S;
    cout<<S.wordPattern("abba", "dog cat cat dog");
    return 0;
}