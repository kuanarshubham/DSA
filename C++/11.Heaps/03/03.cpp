// top k frequnet elemts

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; 
    }
};

vector<int>topKFrequent(vector<int>&v, int k){
    int n=v.size();

    unordered_map<int, int>mpp;

    for(auto it: v) mpp[it]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>pq;

    for(auto it=mpp.begin(); it!=mpp.end(); it++){
        pq.push({it->second, it->first});

        if(pq.size() > k) pq.pop();
    }

    vector<int>ans;

    while(!pq.empty()){
        ans.push_back(pq.top().second); 
        cout<<pq.top().second<<" ";
        pq.pop();
    }

    return ans;
}

int main(){
    vector<int> v = {7, 7, 7, 9, 9, 99, 99, 99, 99, 81, 81, 7, 81, 99};

    topKFrequent(v, 3);
}