// course schedulling 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> courseSchPossible(int n, int p, vector<pair<int, int>>&v){
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

    for(auto it: topo) cout<<it<<" ";
    cout<<endl;

    return n == topo.size() ? topo : vector<int>();
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

    courseSchPossible(n, p, v1);
    courseSchPossible(n, p, v2);
}