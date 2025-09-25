// prims

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int primsMST(vector<vector<int>>&edges, int n){
    // make graph
    vector<pair<int, int>>graph[n];

    for(auto it:edges){
        graph[it[0]].push_back({it[1], it[2]});
    }

    vector<bool>vis(n, false);
    vis[0]=1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, 0});

    int sum=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int wt=it.first, node=it.second;

        if(vis[node]) continue;
        vis[node]=1;
        sum+=wt;
        
        for(auto it2: graph[node]){
            int adjNode=it2.first, adjWt=it2.second;

            if(!vis[adjNode]){
                pq.push({adjWt, adjNode});
            }
        }
    }

    return sum;
}

int main(){}