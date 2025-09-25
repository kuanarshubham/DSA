// shortest path in the binary matrix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>&graph, pair<int, int>src, pair<int, int>dest){
    queue<pair<int, pair<int, int>>>q;
    
    int n=graph.size(), m=graph[0].size();

    vector<vector<int>>dist(n, vector<int>(m, 1e9));
    // {steps, {row, col}}
    q.push({0, {src.first, src.second}});

    while(!q.empty()){
        int step=q.front().first;
        int row=q.front().second.first, col=q.front().second.second;

        q.pop();

        int dr[4]={0, 1, -1, 0}, dc[4]={-1, 0, 0, 1};

        for(int i=0; i<4; i++){
            int nextRow=row+dr[i], nextCol=col+dc[i];

            if(nextRow<n && nextRow>=0 && nextCol>=0 && nextCol<m && graph[nextRow][nextCol]==1 && dist[nextRow][nextCol]>step+1){
                dist[nextRow][nextCol]=step+1;

                if(nextRow==dest.first && nextCol==dest.second) return dist[nextRow][nextCol];

                q.push({dist[nextRow][nextCol], {nextRow, nextCol}});
            }
        }
    }

    return -1;
}

int main(){}