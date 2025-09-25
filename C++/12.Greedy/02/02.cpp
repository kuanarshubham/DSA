// non overlapping interval

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comapartor(pair<int, int>&p1, pair<int, int>&p2){
    return p1.second < p2.second;
}

int numOfRemoval(vector<int>&start, vector<int>&end){
    vector<pair<int, int>>vp;

    int n = start.size();

    for(int i=0; i<n; i++){
        vp.push_back({start[i], end[i]});
    }

    sort(vp.begin(), vp.end(), comapartor);

    int count=1, freeTime=vp[0].second;

    for(int i=1; i<n; i++){
        if(freeTime > vp[i].first){
            count++;
            freeTime=vp[i].second;
        }
    }

    return count;
}

int main(){
    vector<int>start = {0, 3, 1, 5, 5, 7};
    vector<int>end = {5, 4, 2, 9, 7, 9};

    cout<<numOfRemoval(start, end);
}