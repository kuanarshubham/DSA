// unique number of islands -> use Sets

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int, int>>&v, int row0, int col0){

    vis[row][col] = 1;
    v.push_back({row-row0, col-col0});

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, +1};

    for(int i=0; i<4; i++){
        int nrow = row + delRow[i], ncol = col + delCol[i];
        if(nrow<=grid.size()-1 && ncol<=grid[0].size()-1 && nrow>=0 && ncol>=0 && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
            dfs(nrow, ncol, grid, vis, v, row0, col0);
        }
        
    }
}

int numberOfUniqueIsland(vector<vector<int>>grid){
    int rowSize = grid.size(), colSize = grid[0].size();
    vector<vector<int>>vis(rowSize, vector<int>(colSize, 0));

    set<vector<pair<int, int>>>s;

    for(int row = 0; row<rowSize; row++){
        for(int col = 0; col<colSize; col++){
            if(vis[row][col]==0 && grid[row][col]==1){
                vector<pair<int, int>>v;
                dfs(row, col, grid, vis, v, row, col);

                s.insert(v);
            }
        }
    }

    cout<<s.size();

    return s.size();
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0}
    };

    numberOfUniqueIsland(grid);
}