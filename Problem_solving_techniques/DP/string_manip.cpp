#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthAfterTransformations(string s, int t) {
    // O(n^2) solution: TLE
//     for(int i=0;i<t;i++)
//     {
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i] == 'z')
//             {
//                 s.erase(s.begin()+i);
//                 s.insert(i,"ab");
//                 i++;
//             }
//             else s[i]++;
//         }
//     }
//     return s.size()%(1e9+7);
// }

// Idea: do not do explicit string modification, instead track the number of letters
vector<long int> letters(26,0);
vector<long int> new_letters(26,0);
int MOD = (1e9+7);
for(char c: s)
    letters[c-97]++;
bool start = true;
while(t-- != 0)
{
    if(start){
    for(int i=0;i<26;i++)
    {
        if(i!= 25 && letters[i]>0)
        {
            new_letters[i+1] = letters[i];
            letters[i]=0;
        }
        else if(i==25 && letters[i]>0)
        {
            new_letters[0]+=letters[i];
            new_letters[1]+=letters[i];
            letters[i]=0;
        }
    }
    start = false;
}
else{
    for(int i=0;i<26;i++)
    {
        if(i!= 25 && new_letters[i]>0)
        {
            letters[i+1] = new_letters[i];
            new_letters[i]=0;
        }
        else if(i==25 && new_letters[i]>0)
        {
            letters[0]+=new_letters[i];
            letters[1]+=new_letters[i];
            new_letters[i]=0;
        }
    }
    start=true;
}
}
int count=0;
for(int i=0;i<26;i++)
    count += letters[i];
for(int i=0;i<26;i++)
    count += new_letters[i];
return (count)%MOD;
}

int main()
{
    string x = "azbk";
    cout << lengthAfterTransformations(x,1);
    return 0;
}