// traversal technique

// level-wise traversal


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>&graph){
    int n = graph.size();

    // till q is empty run the loop
    queue<int>q;
    q.push(0);

    vector<int>vis(n, 0), ans;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        vector<int>list = graph[node];

        for(auto nodes: list){
            if(!vis[nodes]){
                vis[nodes]=1;
                q.push(nodes);
            }
        }
    }

    return ans;
}

// SC = n + n + n
// TC = n + 2edges