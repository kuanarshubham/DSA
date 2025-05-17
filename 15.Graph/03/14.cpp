//Topo sort - bfs 
//kahn's algo

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topoSortBFS(vector<vector<int>>&g){
    int s = g.size();
    vector<int> vis(s, 0);

    vector<int>incoming(s, 0);

    for(int i=0; i<g.size(); i++){
        for(int j=0; j<g[i].size(); j++){
            incoming[g[i][j]]++;
        }
    }

    queue<int>q;
    
    for(auto i=0; i<incoming.size(); i++){
        if(incoming[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto it: g[front]){
            incoming[it]--;

            if(incoming[it] == 0) q.push(it);
        }
    }

    for(auto it: ans){
        cout<<it<<" ";
    }

    return ans;
}

int main(){
    vector<vector<int>>g = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };

    topoSortBFS(g);
}