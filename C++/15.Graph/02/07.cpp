//rotten oranges

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(){}

int timeToRot(vector<vector<int>>g, int row, int col){
    int n = g.size();
    int m = g[0].size();
    vector<vector<int>>vis(n, vector<int>(m, 0));

    queue<pair<int, int>>q;
    q.push({row, col});
    vis[row][col] = 1;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        if(r<n-1 && !vis[r+1][c] && g[r+1][c] == 1) vis[r+1][c] = 1;
        
    }
}