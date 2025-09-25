//detcet cycle
//using bfs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detectCycle(vector<vector<int>>&g){
    int s = g.size();

    vector<int> incoming(s, 0);

    for(int i=0; i<s; i++){
        for(auto it: g[i]){
            incoming[it]++;
        }
    }

    queue<int>q;
    for(int i=0; i<s; i++){
        if(incoming[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it: g[node]){
            incoming[it]--;

            if(incoming[it] == 0) q.push(it);
        }
    }

    return topo.size() != s ? true : false;
}

int main(){
    vector<vector<int>> g = {
        {},
        {2},
        {3},
        {4, 5},
        {2},
        {}
    };

    cout<<detectCycle(g);
}