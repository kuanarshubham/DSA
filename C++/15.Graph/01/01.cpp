// store the graph in the 
// 1. matrix
// 2. adj list

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void matrix(vector<vector<int>> &arr){
    int edges, nodes;
    cin>>nodes>>edges;

    while(edges){
        int u, v, wt;
        cin>>u>>v>>wt;

        arr[u][v] = wt;
        arr[v][u] = wt;
        edges--;
    }
}

void adjList(vector<vector<int>>&arr, int x){
    int edges, nodes;
    cin>>nodes>>edges;

    for(int i=1; i<=edges; i++){
        int u, v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}

int main(){
    vector<vector<int>> v;

    matrix(v);
}