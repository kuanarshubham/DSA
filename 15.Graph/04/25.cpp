// print shortest path

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<vector<pair<int, int>>>&graph, int src){
    int n=graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>parent(n), dist(n, 1e9);

    iota(parent.begin(), parent.end(), 0);

    int dest=n-1;
    // {distance, node}
    pq.push({0, src});

    while(!pq.empty()){
        int distance=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: graph[node]){
            int adjNode=it.first;
            int adjWt=it.second;

            if(dist[adjNode]>distance+adjWt){
                dist[adjNode]=distance+adjWt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode]=node;
            }
        }
    }

    if(dist[n-1]==1e9) return {-1};
    vector<int>ans;

    int node=n-1;
    while(node!=parent[node]){
        ans.push_back(node);
        node=parent[node];
    }

    ans.push_back(src);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){}