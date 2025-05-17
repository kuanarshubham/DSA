//detct cysle in directed graph
//use dfs algo

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<vector<int>>&g, vector<int>&vis, vector<int>&pathVis){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: g[node]){
        if(!vis[it]){
            if(dfsCheck(it, g, vis, pathVis) == true) return true;
        }
        else if(pathVis[it]){
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool detectCycleDirecttedGraph(vector<vector<int>>&g){
    int s = g.size();

    vector<int>vis(s, 0);
    vector<int>pathVis(s, 0);

    for(int i=0; i<s; i++){
        if(!vis[i]){
            if(dfsCheck(i, g, vis, pathVis) == true){
                return true;
            }
        }
    }
     
    return false;
}

int main(){
    vector<vector<int>> g = {
        {},
        {2},
        {3},
        {4, 7},
        {5},
        {6},
        {},
        {5},
        {9},
        {10},
        {8}
    };

    cout<<detectCycleDirecttedGraph(g);
}