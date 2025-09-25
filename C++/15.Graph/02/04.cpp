//number of provinces i.e disjoint sub-graphs in a graph

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> g, vector<int> &allNodes)
{

    queue<int> q;

    q.push(node);

    allNodes[node] = 1;

    while (!q.empty())
    {
        int frontVal = q.front();
        vector<int> v = g[frontVal];

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
}

int noProvinces(vector<vector<int>>g, vector<int>&allNodes){
    int ans =0;

    for(int i=1; i<allNodes.size(); i++){
        if(allNodes[i] == 0){
            ans++;
            bfs(i, g, allNodes);
        }
    }

    cout<<ans;

    return ans;
}


int main(){
    vector<vector<int>>g = {
        {},
        {2},
        {1, 3},
        {2},
        {5},
        {4, 6},
        {5},
        {8},
        {7}
    };

    vector<int> v(g.size(), 0);

    noProvinces(g, v);
}