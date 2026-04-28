// kahn's algo (topo sort using BFS)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>kah_s_algo(vector<vector<int>>&graph){
    int n=graph.size();

    vector<int>in_deg(n, 0), ans;

    queue<int>q;
    
    // v + e
    for(int i=0; i<n; i++){
        for(auto it: graph[i]) in_deg[it]++;
    }

    // v
    for(int i=0; i<n; i++){
        if(in_deg[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto it: graph[node]){
            in_deg[it]--;
            if(in_deg[it]==0) q.push(it);
        }
    }

    if(ans.size()!=n) return {-1};

    return ans;
}

int main(){

}