// djistra

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<vector<pair<int, int>>>&graph, int src){
    int n=graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dist(n, 1e9);

    dist[src]=0;
    
    // {dist, node}
    pq.push({0, src});

    while(!pq.empty()){
        int distance=pq.top().first, node=pq.top().second;
        pq.pop();

        for(auto it: graph[node]){
            
        }
    }
}

int main(){

}