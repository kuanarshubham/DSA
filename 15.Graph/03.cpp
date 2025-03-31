//dfs tarversal

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int node, vector<vector<int>>g, vector<int>&allNodes, vector<int>&ans){
    ans.push_back(node);
    allNodes[node] = 1;

    for(auto it: g[node]){
        if(!allNodes[it]){
            recc(it, g, allNodes, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>g, vector<int>&allNodes){
    vector<int> ans;

    recc(1, g, allNodes, ans);

    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;

    return ans;
}

int main(){
    vector<vector<int>> g = {
        {},
        {2, 6},
        {1, 3, 4},
        {2},
        {2, 5},
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {9}};

    vector<int> allNodes(g.size(), 0);

    dfs(g, allNodes);
}