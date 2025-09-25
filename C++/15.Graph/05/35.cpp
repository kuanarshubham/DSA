// Krushkal

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent, size;

public:
    DSU(int n){
        this->parent.resize(n+1);
        this->size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int getULTParent(int node){
        if(node==parent[node]){
            return node;
        }

        return this->parent[node]=getULTParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_u=getULTParent(u), ult_v=getULTParent(v);

        if(ult_u==ult_v) return;

        if(size[ult_u]>size[ult_v]){
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};

int krushkalST(vector<vector<int>>edges, int n){
    
    // {u, v, wt}
    for(auto &it:edges){
        int wt=it[2];
        it.pop_back();
        it.insert(it.begin(), wt);
    }
    // {wt, u, v}

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int sum=0;

    for(auto it: edges){
        int wt=it[0], u=it[1], v=it[2];

        if(dsu.getULTParent(u)==dsu.getULTParent(v)) continue;
        else{
            dsu.unionBySize(u, v);
            sum+=wt;
        } 
    }

    return  sum;
}

int main(){}