// Leetcode: https://leetcode.com/problems/unique-number-of-occurrences/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> um;
    for(int i=0; i<arr.size(); i++)
    {
        if(!um.count(arr[i])) //if key not present
            um[arr[i]]=1;
        else //if key present
            um[arr[i]]++;
    }
    unordered_set<int> us;
    unordered_map<int,int>::iterator itr;
    for(itr=um.begin(); itr!=um.end(); itr++)
    {
        us.insert(itr->second);
    }
    if(us.size()!=um.size())
        return false;
    return true;
}

int main()
{
    cout<<boolalpha;
    vector<int> arr={1,2,2,1,1,3};
    cout<<uniqueOccurrences(arr);

    return 0;
}