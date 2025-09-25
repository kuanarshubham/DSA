// safe states
// find the terminal nodes (incoming  = 0)
// reverse the direction of all the nodes
// do topo sort -> the nodes coming out are terminal nodes

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>safeNodes(vector<vector<int>>&g){
    int s = g.size();

    vector<int>safeState;
    queue<int>q;
    vector<int>incoming(s, 0);

    for(int i=0; i<s; i++){
        if(!g[i].size()){
            q.push(i);
        }
    }

    //reverse the graph's direction
    vector<vector<int>>gNew(s);
    for(int i=0; i<s; i++){
        for(auto it: g[i]){
            gNew[it].push_back(i);
            incoming[i]++;
        }
    }

    while(!q.empty()){
        int node =  q.front();
        q.pop();

        safeState.push_back(node);

        for(auto it: gNew[node]){
            incoming[it]--;
            
            if(!incoming[it]) q.push(it);
        }
    }

    for(auto it: safeState) cout<<it<<" ";

    return safeState;
}

int main(){
    vector<vector<int>> g = {
        {1},
        {2},
        {3, 4},
        {4, 5},
        {6},
        {6},
        {7},
        {},
        {1, 9},
        {10},
        {8},
        {9}
    };
    
    safeNodes(g);
}