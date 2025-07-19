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
int bottomToTop(vector<vector<int>>&graph, int )

int main(){}