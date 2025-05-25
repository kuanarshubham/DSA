// N queen

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>&board){

    // col: 0 -> col-1 
    for(int i = 0; i<col; i++){
        if(board[row][i] == '1') return false;
    }

    // upper-left: (row-1, col-1) -> (row-1, col-1, till (row==0 || col==0))

    int i= row, j = col;
    while(i>=0 && j>=0){
        if(board[i--][j--] == '1') return false;
    }

    // lower-left: (row+1, col-1) -> (row+1, col-1, till (row==0 ||  col==0))
    while(col>=0 && row<board.size()){
        if(board[row++][col--] == '1') return false;
    }

    return true;
}

void recc(int col, int n, vector<string>&board, vector<vector<string>>&ans){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row<n; row++){
        if(isSafe(row, col, board)){
            board[row][col] = '1';
            recc(col+1, n, board, ans);
            board[row][col] = '0';
        }
    }
}

vector<vector<string>>allPossibleNQueen(int n){
    vector<vector<string>>ans;

    string value;
    for(int i=0; i<n; i++) value+='0';

    vector<string>board(n, value);

    int col = 0;
    recc(col, n, board, ans);

    for(auto it: ans){
        for(auto it2: it){
            for(auto it3: it2) cout<<it3<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    return ans;

}

int main(){
    int n = 4;

    allPossibleNQueen(n);
}