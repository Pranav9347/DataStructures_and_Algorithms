
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;


queue<tuple<int,int,int>> q;
set<pair<int,int>> visited;
int m,n,start_x,start_y;
bool is_goal(int x, int y)
{
    if(x == start_x && y == start_y)
        return false;
    if(x == 0 || y == 0 || x == m-1 || y == n-1)
        return true;
    return false;
}
void evaluate_neighbor(int x, int y, int spath, vector<vector<char>>& maze)
{
    if(x<0 || y<0 || x>=m || y>=n || maze[x][y] == '+' || visited.count({x,y}))
        return;
    else
    {
        q.push({x,y,spath+1});
        visited.insert({x,y});
    }
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
        if(is_goal(curr_x,curr_y))
            return curr_path;
        evaluate_neighbor(curr_x-1,curr_y,curr_path,maze);// up
        evaluate_neighbor(curr_x+1,curr_y,curr_path,maze);// down
        evaluate_neighbor(curr_x,curr_y-1,curr_path,maze);// left
        evaluate_neighbor(curr_x,curr_y+1,curr_path,maze);// right
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