// account mergeing

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int>parent, size;

    DSU(int n){
        this->parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
        this->size.resize(n+1, 1);
    }

    int ultParent(int node){
        if(parent[node]=node) return node;

        return parent[node]=ultParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u=ultParent(u), ult_v=ultParent(v);

        if(ult_u==ult_v) return;

        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

vector<vector<string>>mergeAccount(vector<vector<string>>&details){
    int n=details.size();
    unordered_map<string, int>nameToId;

    for(int i=0; i<n; i++){
        for(int j=0; j<details[i].size(); j++){
            
        }
    }

    
}

int main(){}