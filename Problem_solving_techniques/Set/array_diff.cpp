#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> answer(2);
    unordered_set<int> usa(nums1.begin(), nums1.end());
    unordered_set<int> usb(nums2.begin(), nums2.end());
    unordered_set<int>::iterator itr;
    for(itr=usa.begin();itr != usa.end(); itr++)
    {
        if(!usb.count(*itr))
            answer[0].push_back(*itr);
    }
    for(itr=usb.begin();itr != usb.end(); itr++)
    {
        if(!usa.count(*itr))
            answer[1].push_back(*itr);
    }
    return answer;
}

int main()
{
    vector<vector<int>> v;
    vector<int> nums1 = {1,2,3}, nums2 = {2,4,6};
    v=findDifference(nums1,nums2);
    for(auto x:v)
    {
        for(auto y:x)
            cout << y <<" ";
        cout<<endl;
    }
    return 0;
}