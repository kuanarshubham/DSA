// dsu using ranks

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>parent, rank;

public:
    DSU(int n){
        this->parent.resize(n);

        for(int i=0; i<n; i++) this->parent[i]=i;

        this->rank.resize(n, 0);
    }

    int findUltPar(int i){
        if(i==parent[i]){
            return i;
        }

        return parent[i] = findUltPar(parent[i]);
    }


    void unionByRank(int u, int v){
        int utl_par_u=findUltPar(u), ult_par_v=findUltPar(v);

        if(utl_par_u==ult_par_v) return;

        if(rank[utl_par_u]>=rank[ult_par_v]){
            parent[ult_par_v]=utl_par_u;
            
            if(rank[ult_par_v]==rank[utl_par_u]) rank[utl_par_u]++;;
        }
        else{
            parent[utl_par_u]=ult_par_v;
        }
    }
};

int main(){}