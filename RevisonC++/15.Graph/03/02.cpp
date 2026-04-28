// topo sort

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph, int node, vector<int>&vis, vector<int>&ans){
    vis[node]=1;

    for(auto adj_node: graph[node]){
        if(!vis[adj_node]){
            dfs(graph, adj_node, vis, ans);
        }
    }

    ans.push_back(node);
}

vector<int>topo_sort(vector<vector<int>>&graph){
    int n=graph.size();

    vector<int>vis(n, 0), ans;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(graph, i, vis, ans);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    
}