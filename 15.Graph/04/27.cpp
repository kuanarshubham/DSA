// path with min effort

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minEffort(vector<vector<int>>&matrix){
    int n=matrix.size(), m=matrix[0].size();

    // diff, row, col
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
    pq.push({0, {0, 0}});

    vector<vector<int>>dist(n, vector<int>(m, 1e9));
    dist[0][0]=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int diff=it.first, row=it.second.first, col=it.second.second;

        if(row==n-1 && col==m-1) return diff;

        int dr[4]={0, 1, -1, 0}, dc[4]={-1, 0, 0, 1};

        for(int i=0; i<4; i++){
            int nextRow=row+dr[i], nextCol=col+dc[i];
            
            if(nextRow<n && nextRow>=0 && nextRow<m && nextCol<=0){
                int newEffort=max(diff, abs(matrix[row][col]-matrix[nextRow][nextCol]));
                
                if(newEffort<dist[nextRow][nextCol]){
                    pq.push({dist[nextRow][nextCol], {nextRow, nextCol}});
                }
            }
        }
    }

    if(dist[n-1][m-1]==1e9) return -1;
}


int main(){}