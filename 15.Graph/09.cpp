// distance of nearest 1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void recc(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &dist)
{

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
                q.push({{i, j}, 0});
        }
    }

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int currDist = q.front().second;

        q.pop();

        vis[row][col] = 1;
        dist[row][col] = currDist;

        if (row > 0 && !vis[row - 1][col] && grid[row - 1][col] == 0)
            q.push({{row - 1, col}, currDist + 1});
        
        if (row < grid.size() - 1 && !vis[row + 1][col] && grid[row + 1][col] == 0)
            q.push({{row + 1, col}, currDist + 1});
        
        if (col > 0 && !vis[row][col - 1] && grid[row][col - 1] == 0)
            q.push({{row, col - 1}, currDist + 1});
        
        if (col < grid.size() - 1 && !vis[row][col + 1] && grid[row][col + 1] == 0)
            q.push({{row, col + 1}, currDist + 1});
    }
}

vector<vector<int>> nearest1(vector<vector<int>> &grid)
{
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));

    recc(grid, vis, dist);

    for(auto it: dist){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return dist;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 1}};

    nearest1(grid);
}