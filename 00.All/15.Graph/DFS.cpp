// traversal 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(vector<vector<int>>&graph, int node, vector<int>&vis, vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto it: graph[node]){
        if(!vis[it]){
            recc(graph, it, vis, ans);
        }
    }
}

vector<int>dfs(vector<vector<int>>&graph){
    int n=graph.size();

    vector<int>ans, vis(n, 0);
    recc(graph, 0, vis, ans);

    return ans;
}

// SC = n(ans) + n(vis) + n(stack space)
// TC = n + 2edges