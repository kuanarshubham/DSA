// bellman ford algo

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>bellmenFord(vector<vector<int>>&edges, int src){
    int n=edges.size();
    vector<int>dist(n, 1e9);
    dist[src]=0;

    for(int i=0; i<n-1; i++){
        for(auto it:edges){
            int u=it[0], v=it[1], wt=it[2];

            if(u+wt<dist[v]) dist[v]=u+wt;
        }
    }

    for(auto it:edges){
        int u=it[0], v=it[1], wt=it[2];

        if(u+wt<dist[v]) return {-1};
    }

    return dist;
}


int main(){}