// LeetCode Problem: https://leetcode.com/problems/find-the-highest-altitude/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int n=gain.size();
    vector<int> abs_alt(n+1);
    abs_alt[0]=0;
    for(int i=1; i<n+1; i++)
    {
        abs_alt[i]=abs_alt[i-1]+gain[i-1];
    }
    for(int i:abs_alt)
        cout<<i<<" ";
    return *max_element(abs_alt.begin(), abs_alt.end());
}

int main()
{
    vector<int> gain={-5,1,5,0,-7};

    cout << largestAltitude(gain);
    return 0;
}