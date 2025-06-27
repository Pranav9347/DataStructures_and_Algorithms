#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
//     (a-(b+c)+d)
// a-b-c+d
    string input;
    stack<char> st;
    string temp;
    cin >> input;
    for(char c: input)
    {
        st.push(c);
        if(c == ')')
        {
            st.pop();
            while(st.top() != '(')
            {
                temp.insert(temp.begin(),st.top()); //"b+c"
                st.pop();
            }
            st.pop(); //( is popped
            
            char sign;
            if(st.empty() || st.top()== '(')
                sign = '+';
            else
                sign = st.top();
            for(char x: temp)
            {
                if(isalpha(x))
                {
                    st.push(x);
                }
                else
                {
                    if(sign == '+')
                        st.push(x);
                    else if(sign == '-')
                    {
                        if(x == '+')
                        {
                            st.push('-');
                        }
                        if(x == '-')
                        {
                            st.push('+');
                        }
                    }
                }
            }
            temp.clear();
        }
        
    }
    while(!st.empty())
    {
        temp.insert(temp.begin(),st.top()); //"b+c"
        st.pop();
    }
    cout << temp;
}