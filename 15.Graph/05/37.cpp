// operration to make the n/w connected

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

int minOperation(int n, vector<vector<int>>&edges){
    DSU disj(n);
    int extarneousEdges=0, clusters=0;

    for(auto it: edges){
        int u=it[0], v=it[1], wt=it[2];

        if(disj.ultParent(u)==disj.ultParent(v)) extarneousEdges++;
        else{
            disj.unionBySize(u, v);
        }
    }

    for(int i=0; i<n; i++){
        if(disj.parent[i]==i) clusters++;
    }

    if(clusters<=extarneousEdges) return clusters;
    
    return -1;
}

int main(){}