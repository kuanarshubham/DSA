#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>>g, vector<int>&vis){
    queue<pair<int, int>>q;

    q.push({node, -1});
    vis[node] = 1;

    while(!q.empty()){
        int currNode = q.front().first;
        int parentNode = q.front().second;

        for(auto it: g[node]){
            


            



            
        }
    }
}

bool detectCycle(vector<vector<int>>g){
    vector<int> vis(g.size(), 0);

    for(int i=1; i<vis.size(); i++){
        if(!vis[i]){
            if(bfs(i, g, vis)){
                return true;
            }
        }
    }

    return false;
}