// number of wasy to reach the destinantion

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minTime(int n, vector<vector<int>>&edges){
    vector<pair<int, int>>graph[n];

    for(auto it: edges){
        graph[it[0]].push_back({it[1], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<vector<pair<int, int>>>>pq;
    pq.push({0, 0});

    vector<int>dist(n, 1e9), ways(n, 0);
    ways[0]=1;
    dist[0]=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int distance=it.first, node=it.second;

        for(auto it2: graph[node]){
            int adjNode=it2.second, adjDistance=it2.first;

            if(distance+adjDistance<dist[adjNode]){
                dist[adjNode]=distance+adjDistance;
                ways[adjNode]=ways[node];
                pq.push({dist[adjNode], adjNode});
            }

            if(distance+adjDistance==dist[adjNode]){
                ways[adjNode]+=ways[node];
            }
        }
    }

    return ways[n-1];
}

int main(){}