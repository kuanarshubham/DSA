//cycle via bfs and dfs 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>>&g, vector<int>&vis){
    queue<pair<int, int>>q;

    q.push({node, -1});
    vis[node] = 1;

    while(!q.empty()){
        int currNode = q.front().first;
        int parentNode = q.front().second;
        q.pop();

        for(auto adjNode: g[currNode]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                cout<<"adjNode: "<<adjNode<<endl;
                q.push({adjNode, currNode});
            }
            else if(adjNode != parentNode){
                cout<<parentNode<<" -> "<<adjNode<<endl;
                return true;
            }
        }
    }

    return false;
}

bool detectCycle(vector<vector<int>>g){
    vector<int> vis(g.size(), 0);

    for(int i=0; i<vis.size(); i++){
        if(!vis[i]){
            if(bfs(i, g, vis)){
                return true;
            }
        }
    }

    return false;
}

int main(){
    vector<vector<int>>graph = {
        {},
        {2, 3},
        {1, 4},
        {1},
        {2},
        {6},
        {5},
        {8, 9},




        


        {7, 9},
        {7, 8}
    };


    

    cout<<detectCycle(graph);
}