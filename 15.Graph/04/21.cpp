// shortest path in UG
// wt of each node is 1

// apply a basic bfs

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>shortestDistanceStriver(vector<vector<int>>&g, int src){
    int s = g.size();
    vector<int> dist(s, INT_MAX);

    queue<int>q;
    q.push(src);

    dist[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: g[node]){
            if(dist[it] > dist[node]+1){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    for(auto it: dist) cout<<it<<" ";
    cout<<endl;

    return dist;
}

vector<int>shortestDistanceMe(vector<vector<int>>&g, int src){
    int s = g.size();
    vector<int> dist(s, INT_MAX);
    vector<int> vis(s, 0);

    queue<pair<int, int>>q;
    q.push({src, 0});

    dist[src] = 0;

    while(!q.empty()){
        int u = q.front().first;
        int dist_till = q.front().second;
        q.pop();


        for(auto it: g[u]){
            if(!vis[it]){
                if(dist[it]> dist_till + 1) dist[it] = dist_till+1;
                q.push({it, dist[it]});
                vis[it] = 1;
            }
        }
    }

    for(auto it: dist) cout<<it<<" ";
    cout<<endl;

    return dist;
}

int main(){
    vector<vector<int>>g = {
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 4},
        {3, 4},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {6, 7}
    };

    

    shortestDistanceStriver(g, 4);
    cout<<endl;
    shortestDistanceMe(g, 4);
    cout<<endl;

}