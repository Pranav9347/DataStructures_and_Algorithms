// LeetCode Problem: https://leetcode.com/problems/asteroid-collision/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    int x;
    reverse(asteroids.begin(),asteroids.end());
    stack<int> st;
    for(int i: asteroids)
        st.push(i);
    while(!st.empty())
    {
        x = st.top();
        if(x >= 0)
        {
            ans.push_back(x);
            st.pop();
        }
        else
        {
            if(ans.size()==0)
            {
                ans.push_back(x);
                st.pop();
                continue;
            }
            if(ans.back()<0)
            {
                ans.push_back(x);
                st.pop();
                continue;
            }
            while(ans.size()>0 && ans.back()>0)
            {
                if(abs(x)<abs(ans.back()))
                {
                    st.pop();
                    break;
                }
                else if(abs(x)>abs(ans.back()))
                {
                    ans.pop_back();
                    if(ans.size()==0)
                    {
                        ans.push_back(x);
                        st.pop();
                    }
                }
                else
                {
                    ans.pop_back();
                    st.pop();
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v={-2,-1,1,2};
    v = asteroidCollision(v);
    for(auto x:v)
        cout<<x<<" ";
    return 0;
}