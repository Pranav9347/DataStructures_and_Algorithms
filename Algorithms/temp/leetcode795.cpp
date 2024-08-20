#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int max(vector<int> A, int p1, int p2)
    {
        int max = A[p1];
        for(int i=p1;i<p2+1;i++)
        {
            if(A[i]>max)
                max = A[i];
        }
        return max;
    }
    bool in_range(int x, int left, int right)
    {
        if(x<=right && x>=left)
        {
            return true;
        }
        return false;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int p1=0,p2=0,c=0;
        while(p1<=nums.size()-1 && p2<=nums.size())
        {
            if(p2 == nums.size())
            {
                p1++;
                p2 = p1;
            }
            else if(p1==p2 && in_range(nums[p1],left,right))
            {
                c++;
                p2++;
            }
            else if(p1==p2 && nums[p1]<right)
            {
                p2++;
            }
            else if((nums[p2]<max(nums,p1,p2)&&in_range(max(nums,p1,p2),left,right)) || in_range(nums[p2],left,right))
            {
                c++;
                p2++;
            }
            else
            {   
                p1++;
                p2=p1;
            }
        }
        return c;
    }
};
int main()
{
    Solution S;
    vector<int> v={73,55,36,5,55,14,9,7,72,52};
    cout<<S.numSubarrayBoundedMax(v, 32, 69);
    return 0;
}