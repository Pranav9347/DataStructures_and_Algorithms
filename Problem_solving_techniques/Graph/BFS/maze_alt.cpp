// Leetcode: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;


queue<tuple<int,int,int>> q;
set<pair<int,int>> visited;
int m,n,start_x,start_y;
vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_goal(int x, int y)
{
    if(x == start_x && y == start_y)
        return false;
    if(x == 0 || y == 0 || x == m-1 || y == n-1)
        return true;
    return false;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
{
    m = maze.size();
    n = maze[0].size(); 
    start_x = entrance[0];
    start_y = entrance[1];
    q.push({start_x,start_y,0});
    visited.insert({start_x,start_y});
    while(!q.empty())
    {
        auto& [curr_x, curr_y, curr_path] = q.front();
        for(auto& [dx,dy]: directions)
        {
            int x = curr_x+dx;
            int y = curr_y+dy;
            if(x<0 || y<0 || x>=m || y>=n || maze[x][y] == '+' || visited.count({x,y}))
                continue;
            if(is_goal(x,y))
                return curr_path+1;
            else
            {
                q.push({x,y,curr_path+1});
                visited.insert({x,y});
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };
    vector<int> entrance = {1, 0}; // Starting point in the maze

    int result = nearestExit(maze, entrance);
    cout << result << endl;

    return 0;
}