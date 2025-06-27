// LeetCode Problem: https://leetcode.com/problems/decode-string/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std; 

string decodeString(string s) { 
    string temp, dig, new_str;
    int num;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] != ']')
            st.push(s[i]);
        else
        {
            while(st.top() != '[')
            {
                temp.insert(temp.begin(), st.top());
                st.pop();
            }
            st.pop(); // '[' popped
            while(!st.empty() && isdigit(st.top()))
            {
                dig.insert(dig.begin(), st.top());
                st.pop();
            }
            num = atoi(dig.c_str());
            while(num!=0)
            {
                new_str += temp;
                num--;
            }
            for(int j=0;j<new_str.length();j++)
                st.push(new_str[j]);
            new_str.clear();
            temp.clear();
            dig.clear();
        }
    }
    while(!st.empty())
    {
        new_str += st.top();
        st.pop();
    }
    reverse(new_str.begin(),new_str.end());
    return new_str;
}

int main()
{
    cout << decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}