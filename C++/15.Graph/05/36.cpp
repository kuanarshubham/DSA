// number of provinces

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int>parent, size;
    
    DSU(int n){
        this->parent.resize(n);

        for(int i=0; i<n; i++) this->parent[i]=i;

        this->size.resize(n, 1);
    }

    int findUltPar(int i){
        if(i==parent[i]){
            return i;
        }

        return parent[i] = findUltPar(parent[i]);
    }

    void unionBySize(int u, int v){
        int utl_par_u=findUltPar(u), ult_par_v=findUltPar(v);

        if(utl_par_u==ult_par_v) return;

        if(size[utl_par_u]>=size[ult_par_v]){
            parent[ult_par_v]=utl_par_u;
            
            size[utl_par_u]+=size[ult_par_v];
        }
        else{
            parent[utl_par_u]=ult_par_v;
            size[ult_par_v]+=size[utl_par_u];
        }
    }
};

int numProvinces(vector<vector<int>>&matrix){
    int n=matrix.size(), m=matrix[0].size();

    DSU disj(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==1){
                disj.unionBySize(i, j);
            }
        }
    }

    int count=0;

    for(int i=0; i<n; i++){
        if(disj.parent[i]==i) count++;
    }

    return count;
}

int main(){}