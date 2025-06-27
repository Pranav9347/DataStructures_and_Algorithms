// Leetcode: https://leetcode.com/problems/rotting-oranges/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    // Multi-source BFS
    queue<tuple<int,int,int>> q;
    int m, n, max_minutes;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // initialize queue with rotten orange states
        for(int i=0; i<m; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty())
        {
            auto& [curr_x, curr_y, curr_min] = q.front();
            for(auto& [dx,dy]: directions)
            {
                int x = curr_x+dx;
                int y = curr_y+dy;
                if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == 0 || grid[x][y] ==2)
                    continue;
                else
                {
                    q.push({x,y,curr_min+1});
                    max_minutes = max(max_minutes, curr_min+1);
                    grid[x][y] = 2;
                }
            }
            q.pop();
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return max_minutes;
    }
};