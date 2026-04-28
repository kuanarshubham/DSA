// cycle detection in DG using DFS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool dfs(vector<vector<int>>&graph, int node, vector<int>&vis, vector<int>&path_vis){
    vis[node]=1;
    path_vis[node]=1;
    
    for(int adj_node: graph[node]){
        if(vis[adj_node]==0){
            bool dfs_dive = dfs(graph, adj_node, vis, path_vis);
            if(dfs_dive==true) return true;
        }
        else if(vis[adj_node]==1 && path_vis[adj_node]==1){
            return true;
        }
    } 
    
    path_vis[node]=0;
    return false;
}

bool cycle_detection(vector<vector<int>>&graph){
    int n=graph.size();
    
    vector<int>path_vis(n, 0), vis(n, 0);
    
    for(int i=0; i<n; i++){
        if(vis[i]==0){
            if(dfs(graph, i, vis, path_vis)==true) return true;
        }
    }

    return false;
}

int main(){
    vector<vector<int>>graph = {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {2, 9},
        {10},
        {8}
    };

    cout<<cycle_detection(graph)<<endl;
}