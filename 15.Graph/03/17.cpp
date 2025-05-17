// course schedulling 1
// detect cycle using kahn's algo or dfs cycle detect
// but if asked to get order of execution, uses's kahn's algo and send the topo sort

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool courseSchPossible(int n, int p, vector<pair<int, int>>&v){
    vector<int> incoming(n, 0);
    
    for(int i=0; i<p; i++){
        incoming[v[i].first]++;
    }

    queue<int>q;
    for(int i=0; i<n; i++){
        if(incoming[i] == 0) q.push(i);
    }

    //make graph
    map<int, vector<int>>mpp;
    for(int i=0; i<p; i++){
        mpp[v[i].second].push_back(v[i].first); 
    }

    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it: mpp[node]){
            incoming[it]--;

            if(incoming[node]==0) q.push(it);
        }
    }

    return n == topo.size() ? true : false;
}

int main(){
    int n = 4;
    int p = 3;
    
    vector<pair<int, int>>v1 = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    vector<pair<int, int>>v2 = {
        {1, 2},
        {4, 3},
        {2, 4},
        {4, 1}
    };

    cout<<courseSchPossible(n, p, v2);
}