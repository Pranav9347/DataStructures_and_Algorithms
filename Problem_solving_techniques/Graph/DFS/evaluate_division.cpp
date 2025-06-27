// Leetcode: https://leetcode.com/problems/evaluate-division/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> div_graph;
    unordered_set<string> visited;
    double DFS(string src, string dest, double product)
    {
        visited.insert(src);
        for(auto& p:div_graph[src])
        {
            auto& [neighbor, weight] = p;
            if(!visited.count(neighbor))
            {
                if(neighbor == dest)
                    return product*weight;
                double ans = DFS(neighbor, dest, product*weight);
                if(ans == -1)
                    continue;
                else return ans;
            } 
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //get the set of all variables
        unordered_set<string> variables;
        for(auto& eq: equations)
        {
            variables.insert(eq[0]);
            variables.insert(eq[1]);
        }
        int n = variables.size();
        //construct the division graph
        for(int i=0;i<equations.size();i++)
        {
            vector<string> eq = equations[i];
            div_graph[eq[0]].push_back({eq[1],values[i]});
            div_graph[eq[1]].push_back({eq[0],1.0/values[i]});
        }
        vector<double> output;
        for(auto& v: queries)
        {   
            string var1 = v[0], var2 = v[1];
            if(!variables.count(var1) || !variables.count(var2))
            {
                output.push_back(-1.0);
                continue;
            }
            if(var1 == var2)
            {
                output.push_back(1.00);
                continue;
            }
            visited.clear();
            output.push_back(DFS(var1,var2,1));
        }
        return output;
    }
};