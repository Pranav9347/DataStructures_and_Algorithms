#include <string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for(int i=0; i<operations.size();i++)
        {
            if(operations[i] == "C")
                v.erase(v.begin()+i-1);
            else if(operations[i] == "D")
                v.push_back(2*(*(v.end()-1)));
            else if(operations[i] == "+")
                v.push_back(*(v.end()-1)+*(v.end()-2));
            else v.push_back(stoi(operations[i]));
        }
        int sum=0;
        for(auto x:v)
        {
            sum+=x;
        }
        return sum;
    }
};
int main()
{ 
    Solution S;
    vector<string> operations = {"5","2","C","D","+"};
    cout<<S.calPoints(operations);
    return 0;
}