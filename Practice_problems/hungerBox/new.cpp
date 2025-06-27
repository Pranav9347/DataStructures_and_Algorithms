#include <iostream>
#include <vector>
#include <string>
using namespace std;
// # newfile
// # s1 = "ADOBECODEBANC" about 10^5 chars and alphabets only
// # s2 ="ABC"
// # Resc= "BANC"

// # Given a string s1, return the substring of min size such that another string s2's all characters are contained in the substring

string s1 = "ADOBECODEBANC";
string s2 = "ABC";
vector<int> low_alpha(26,0);
vector<int> up_alpha(26,0);
vector<int> low_sol(26,0);
vector<int> up_sol(26,0);

int min_len = INT_MAX;
string min_str = "";

bool same(vector<int>& v1, vector<int>& v2)
{
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    for(char x: s2)
    {
        if(isupper(x))
            up_alpha[x-'A']++;
        if(islower(x))
            low_alpha[x-'a']++;
    }
    for(int i=0;i<s1.length();i++)
    {
        if(same(low_alpha, low_sol) && same(up_alpha, up_sol))
        {
            min_len = i;
            min_str = s1.substr(0,i);
            cout << min_str;
        }
        if(s2.find(s1[i]))
        {
            if(isupper(s1[i]))
            {
                up_sol[s1[i]-'A']++;
            }
            if(islower(s1[i]))
            {
                low_sol[s1[i]-'a']++;
            }
        }
    }
    return 0;
}
// for i in range(len(s1)):
//     for j in range(len(s1)):
//         if s1[i] in s2:
//             j += 1
        