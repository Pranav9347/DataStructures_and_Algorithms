// Leetcode: https://leetcode.com/problems/maximum-subsequence-score/
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), remove;
        long long score=0,maxSum=0;
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++)
        {
            v[i].first = nums1[i];
            v[i].second = nums2[i];
        }
        sort(v.begin(),v.end(),[](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<n;i++)
        {
            minHeap.push(v[i].first);
            maxSum+=v[i].first;
            if(minHeap.size() > k)
            {
                remove = minHeap.top();
                minHeap.pop();
                maxSum -= remove;
            }
            if(minHeap.size() == k)
            {
                score = max(score, maxSum*v[i].second);
            }
        }
        return score;
    }
};