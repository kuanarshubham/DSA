// why DSU
// Done so that to chcek if 2 graphs are part of the same graph in O(1)

// TC(to get parent) = O(4*alpha) = TC(to unionisze)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>size, parent;

    DSU(int n){
        size.resize(n+1, 0);
        parent.resize(n+1, 0);
    }

    int findParent(int n){
        if(n==parent[n]) return n;

        return parent[n] = findParent(parent[n]);
    }  

    void unionSize(int u, int v){
        int ult_u = findParent(u), ult_v=findParent(v);

        if(ult_u==ult_v) return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] =  ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

// this does not gives you a Graph
// rather this gives you a new form of DS
// used in MST(Krushkal)



// findParent is done using Path compression
// this means, we can give you the parent directly, but to reduce the time to constant we done recusriion and give Ulimate Parent in constant time