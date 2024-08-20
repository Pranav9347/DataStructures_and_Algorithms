#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top() == ')' || st.top() =='}' || st.top() ==']')
                return false;
            else if(st.top()=='[')
            {
                if(s[i] == ')' || s[i] == '}')
                    return false;
                else if(s[i] == ']')
                {
                    st.pop();
                    continue;
                }
                else st.push(s[i]);
            }
            else if(st.top()=='{')
            {
                if(s[i] == ')' || s[i] == ']')
                    return false;
                else if(s[i] == '}')
                {
                    st.pop();
                    continue;
                }
                else st.push(s[i]);
            }
            else
            {
                if(s[i] == '}' || s[i] == ']')
                    return false;
                else if(s[i] == ')')
                {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        else return false;
    }
};
int main()
{
    Solution S;
    bool x = S.isValid("()");
    cout<<x<<endl;
}