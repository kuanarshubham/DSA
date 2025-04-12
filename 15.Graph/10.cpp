// number of enclaves

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numOfEnclaves(vector<vector<int>> grid)
{
    vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < grid.size(); i++)
    {
        if (grid[i][0] == 1)
            q.push({i, 0});
        if (grid[i][grid.size() - 1] == 1)
            q.push({i, grid.size() - 1});
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        if (grid[0][i] == 1)
            q.push({0, i});
        if (grid[grid[0].size() - 1][i] == 1)
            q.push({grid
            
            
            
            
            [0].size() - 1, i});
    }

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        vis[row][col] = 1;
        q.pop();

        if (row > 0 && grid[row - 1][col] == 1)
            q.push({row - 1, col});
        if (row < grid.size() - 1 && grid[row + 1][col] == 1)
            q.push({row + 1, col});
        if (col > 0 && grid[row][col - 1] == 1)
            q.push({row, col - 1});
        if (col < grid.size() - 1 && grid[row][col + 1] == 1)
            q.push({row, col + 1});
    }

    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
                count++;
        }
    }

    cout<<count<<endl;

    return count;
}

int main()
{
    vector<vector<int>>grid = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    numOfEnclaves(grid);
}