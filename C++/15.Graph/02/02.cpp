#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> g, vector<int> &allNodes)
{
    vector<int> ans;
    queue<int> q;

    q.push(1);

    allNodes[1] = 1;

    while (!q.empty())
    {
        int frontVal = q.front();
        vector<int> v = g[frontVal];

        ans.push_back(frontVal);

        for (int i = 0; i < v.size(); i++)
        {
            if (allNodes[v[i]] == 0)
            {
                allNodes[v[i]] = 1;
                q.push(v[i]);
            }
        }

        q.pop();
    }

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return ans;
}

int main()
{
    vector<vector<int>> g = {
        {},
        {2, 6},
        {1, 3, 4},
        {2},
        {2, 5},
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {9}};

    vector<int> allNodes(g.size(), 0);

    bfs(g, allNodes);
}