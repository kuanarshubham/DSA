// rat in a maze

// for traversing through ecah cell once use a vis array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int row, int col, vector<vector<int>>&vis, vector<string>&maze, string &temp, vector<string>&ans){

    if((row == maze.size()-1 && col == maze.size()-1)){
        ans.push_back(temp);
        return;
    }


    if(row<maze.size()-1 && maze[row+1][col] == '1' && !vis[row+1][col]){
        vis[row+1][col] = 1;
        temp.push_back('D');
        recc(row+1, col, vis, maze, temp, ans);
        temp.pop_back();
        vis[row+1][col] = 0;
    }
    
    if(col>0 && maze[row][col-1] == '1' && !vis[row][col-1]){

        vis[row][col-1] = 1;
        temp.push_back('L');
        recc(row, col-1, vis, maze, temp, ans);
        temp.pop_back();
        vis[row][col-1] = 0;
    }

    if(col<maze.size()-1 && maze[row][col+1] == '1' && !vis[row][col+1]){

        vis[row][col+1] = 1;
        temp.push_back('R');
        recc(row, col+1, vis, maze, temp, ans);
        temp.pop_back();
        vis[row][col+1] = 0;
    }

    if(row>0 && maze[row-1][col] == '1' && !vis[row-1][col]){

        vis[row-1][col] = 1;
        temp.push_back('U');
        recc(row-1, col, vis, maze, temp, ans);
        temp.pop_back();
        vis[row-1][col] = 0;
    }
}

vector<string>allPaths(vector<string>&maze){
    vector<string>ans;
    string temp;
    vector<vector<int>> vis(maze.size(), vector<int>(maze.size(), 0));

    recc(0, 0, vis, maze, temp, ans);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return ans;
}

int main(){
    vector<string>maze = {"1000", "1101", "1100", "0111"};

    allPaths(maze);
}