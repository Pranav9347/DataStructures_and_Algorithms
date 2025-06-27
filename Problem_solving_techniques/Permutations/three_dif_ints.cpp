#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2,2,2,8,8};
    while(next_permutation(v.begin(),v.end()))
    {
        for(int x:v)
            cout<<x;
        cout<<endl;
    }
        
}
