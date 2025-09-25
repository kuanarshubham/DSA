// start from first row and end at last row

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int memo(vector<vector<int>>& graph, int row, int col, int n, int m, vector<vector<int>>& dp){
    if (col < 0 || col >= m) return INT_MIN; // out of bounds

    if (row == n - 1) return graph[row][col]; // base case

    if (dp[row][col] != -1) return dp[row][col];

    int bottom      = memo(graph, row + 1, col, n, m, dp);
    int bottomRight = memo(graph, row + 1, col + 1, n, m, dp);
    int bottomLeft  = memo(graph, row + 1, col - 1, n, m, dp);

    return dp[row][col] = graph[row][col] + max({bottom, bottomRight, bottomLeft});
}

int bottomToTop(vector<vector<int>>&graph){
    int n=graph.size(), m=graph[0].size();

    int dp[n][m] = {-1};

    for(int i=0; i<m; i++) dp[0][i] = graph[0][i];

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            int bottom = graph[i][j]+dp[i-1][j], left_bottom=INT_MIN, right_bottom=INT_MIN;

            if(j>0) left_bottom=graph[i][j]+dp[i-1][j-1];
            if(j<m-1) right_bottom=graph[i][j]+dp[i-1][j+1];

            dp[i][j]=max(bottom, left_bottom, right_bottom);
        }
    }

    int maxi=INT_MIN;
    for(int i=0; i<m; i++){
        maxi = max(maxi, dp[n-1][i]);
    }

    return maxi;
}

int spaceOpt(vector<vector<int>>&graph){
    int n=graph.size(), m=graph[0].size();

    vector<int> prev(m), curr(m);

    for(int i=0; i<m; i++) prev[i] = graph[0][i];

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int bottom = graph[i][j]+prev[j], left_bottom=INT_MIN, right_bottom=INT_MIN;

            if(j>0) left_bottom=graph[i][j]+prev[j-1];
            if(j<m-1) right_bottom=graph[i][j]+prev[j+1];

            curr[j]=max(bottom, left_bottom, right_bottom);
        }

        prev=curr;
    }

    int maxi=INT_MIN;
    for(auto it: prev) maxi=max(maxi, it);

    return maxi;
}

int main(){}