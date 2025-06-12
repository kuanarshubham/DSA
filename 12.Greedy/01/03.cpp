// short job first

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float avgWaitingTime(vector<int>&j){
    int n=j.size(), waitTime=0, sum=0;

    for(int i=0; i<n; i++) sum += j[i];

    priority_queue<int>pq(j.begin(), j.end());

    while(!pq.empty()){
        waitTime += (sum-pq.top());
        sum -= pq.top();
        pq.pop();
    }

    return float(waitTime/n);
}

int main(){
    vector<int>jobTime = {1, 2, 3, 4};

    cout<<avgWaitingTime(jobTime);
}