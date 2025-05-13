// number of islands (island - the number of 1's connected to each other)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<char>>grid, vector<vector<int>>&refGrid){
    refGrid[row][col] = 1;
    queue<pair<int, int>> qp;

    int n = grid.size();
    int m = grid[0].size();

    qp.push({row, col});

    while(!qp.empty()){
        int row = qp.front().first;
        int col = qp.front().second;

        qp.pop();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int dr = row+i;
                int dc = col+j;

                if(dr>=0 && dc>=0 && dr<n && dc<m && grid[dr][dc]=='1' && refGrid[dr][dc] == 0){
                    refGrid[dr][dc] = 1;
                    qp.push({dr, dc});
                }
            }
        }
    }
}

int numOfIsland(vector<vector<char>>&grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>refGrid(n, vector<int>(m, 0));

    int ans = 0;

    for(int row = 0; row<n; row++){
        for(int col = 0; col<m; col++){
            if(grid[row][col] == '1' && refGrid[row][col] == 0){
                ans++;
                bfs(row, col, grid, refGrid);
            }
        }
    }

    cout<<ans;
    return ans;
}

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '1', '1'},
        {'0', '0', '1', '0'},
        {'1', '0', '0', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'},
    };

    numOfIsland(grid);
}