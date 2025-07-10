// min number of ways for multiplication

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfWays(vector<int>&nums, int start, int end){
    // steps, value
    queue<pair<int, int>>q;
    q.push({0, start});

    vector<int>dist(9999, 1e9);
    dist[start]=0;

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        int node=it.second, steps=it.first;

        for(auto it2: nums){
            int mutipliedvalue = it2*node;

            if(mutipliedvalue>=1e5) mutipliedvalue%=(int)1e5;

            if(mutipliedvalue==end) return steps+1;

            if(dist[mutipliedvalue]>steps+1){
                dist[mutipliedvalue]=steps+1;
                q.push({steps+1, mutipliedvalue});
            }
        }
    }

    return -1;
}

int main(){}