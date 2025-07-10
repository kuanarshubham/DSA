// min cost flight with k stops


// change the proirity of queue pointer's element, 
// before : distance>node>.....
// after : stops>node>distance>....

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cheapestFlight(vector<vector<pair<int, int>>>&graph, int src, int dest, int k){
    queue<pair<int, pair<int, int>>>q;

    // stops, node, dist
    int n=graph.size();
    q.push({0, {src, 0}});

    vector<int>dist(n, 1e9);
    dist[src]=0;

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stops=it.first, node=it.second.first, distance=it.second.second;

        for(auto it2: graph[node]){
            int adjNode=it2.first, adjDistance=it2.second;

            if(stops+1<=k && distance+adjDistance<dist[adjNode]){
                dist[adjNode]=distance+adjDistance;
                q.push({stops+1, {adjNode, dist[adjNode]}});
            }
        }
    }

    if(dist[dest]==1e9) return -1;

    return dist[dest];
}

int main(){

}