// flood gate

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int color, int val, vector<vector<int>> &g, vector<vector<int>> &vis, vector<vector<int>> &ans)
{
    if(row>=g.size() || col>=g[0].size()) return;
    vis[row][col] = 1;
    ans[row][col] = color;

    if (row < g.size() - 1 && !vis[row + 1][col] && g[row + 1][col] == val)
        dfs(row + 1, col, color, val, g, vis, ans);

    if (col < g[0].size() - 1 && !vis[row][col + 1] && g[row][col + 1] == val)
        dfs(row, col + 1, color, val, g, vis, ans);

    if (row >= 1 && !vis[row - 1][col] && g[row - 1][col] == val)
        dfs(row - 1, col, color, val, g, vis, ans);

    if (col >= 1 && !vis[row][col - 1] && g[row][col - 1] == val)
        dfs(row, col - 1, color, val, g, vis, ans);
}

vector<vector<int>> coloredGraph(vector<vector<int>> g, int row, int col, int color)
{
    int n = g.size();
    int m = g[0].size();

    vector<vector<int>> ans(g);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int val = g[row][col];

    dfs(row, col, color, val, g, vis, ans);

    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }

        cout << endl;
    }

    return ans;
}

int main()
{
    vector<vector<int>> g = {
        {1, 1, 1},
        {2, 2, 0},
        {2, 2, 2}};

    coloredGraph(g, 2, 0, 3);
}