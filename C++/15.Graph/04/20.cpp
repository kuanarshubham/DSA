// shortest path in DAG
// use Topo sort
// store the ggraph in pair<int, int> = <node, wt>
// source can be any node

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// topo sort using any - bfs or dfs
// vector<int> dist(topo.size(), INT_MAX)
// make the dist[src_node] = 0

void dfs(vector<vector<pair<int, int>>>&g, int node, stack<int>&st, vector<int>&vis){
    vis[node] = 1;

    for(auto it: g[node]){
        if(!vis[it.first]) dfs(g, it.first, st, vis);
    }

    st.push(node);
}

vector<int> minDistance(vector<vector<pair<int, int>>>&g, int src){
    int s = g.size();
    vector<int> vis(s, 0);
    stack<int>st;

    for(int i=0; i<s; i++){
        if(!vis[i]) dfs(g, i, st, vis);
    }

    // introduce dist array
    vector<int> dist(s, INT_MAX);

    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: g[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }

    for(auto it: dist) cout<<it<<" ";
    cout<<endl;

    return dist;
}


int main(){
    vector<vector<pair<int, int>>> g = {
        {{1, 2}},
        {{3, 1}},
        {{3, 3}},
        {},
        {{0, 3}, {2, 1}},
        {{4, 1}},
        {{4, 2}, {5, 3}}
    };

    minDistance(g, 6);
}