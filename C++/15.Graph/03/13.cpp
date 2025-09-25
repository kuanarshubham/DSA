//topo sort - dfs 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&g, int node, stack<int>&st, vector<int>&vis){
    vis[node] = 1;

    for(auto it: g[node]){
        if(!vis[it]) dfs(g, it, st, vis);
    }

    st.push(node);
}

vector<int> topoSort(vector<vector<int>>&g){
    int size = g.size();

    vector<int> vis(size, 0);
    stack<int> st;

    for(int i=0; i<size; i++){
        if(!vis[i]) dfs(g, i, st, vis);
    }

    vector<int> ans;
    for(; !st.empty(); st.pop()){
        ans.push_back(st.top());
        cout<<st.top()<<" ";
    }

    cout<<endl;

    return ans;
}


int main(){
    vector<vector<int>> g = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };

    topoSort(g);
}