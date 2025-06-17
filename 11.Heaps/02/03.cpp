// task scheduling

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int timeTaken(vector<char>&v, int k){
    int n=v.size();

    vector<int>mpp(26, 0);

    for(int i=0; i<n; i++){
        mpp[v[i] - 'A']++;
    }

    priority_queue<int>pq;

    for(int i=0; i<26; i++){
        if(mpp[i] > 0) pq.push(mpp[i]);
    }

    int time=0;

    while(!pq.empty()){
        
        vector<int>temp;

        for(int i=1; i<=k+1; i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }

        for(auto it: temp){
            if(it>0) pq.push(it);
        }

        if(pq.empty()) time+=temp.size();
        else time+=k+1;
    }

    return time;
}

int main(){
    vector<char>v = {'A', 'B', 'A', 'A', 'C', 'D', 'B', 'A'};

    cout<<timeTaken(v, 2);
}