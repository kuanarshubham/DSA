// bipatite graph

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isBipatite(vector<vector<int>>&g){
    vector<int>vis(g.size(), -1);

    //color - 0/1
    queue<int>q;
    q.push(1);

    int color = 0;
    vis[1] = color;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        vector<int> v = g[node];

        for(int i=0; i<v.size(); i++){
            if(vis[v[i]] == -1) vis[v[i]] = color;
            else if(vis[v[i]] == 1 && color == 1) return false;
            else if (vis[v[i]] == 0 && color == 0) return false;

            q.push(v[i]);
        }

        color = color==0? 1: 0;
    }

    return true;
}

int main(){
    vector<vector<int>>g = {
        {},
        {2},
        {1, 3, 6},
        {2, 4},
        {3, 5, 7},
        {4, 6},
        {2, 5},
        {4, 8},
        {8}
    };

    vector<vector<int>>g1= {
        {},
        {2}, 
        {1, 3},
        {2, 4},
        {2}
    };



    cout<<isBipatite(g1);
}