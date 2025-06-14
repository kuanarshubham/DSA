// min no of platform

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b){
    return a.second.second < b.second.second;
} 

int platform(vector<int>arrival, vector<int>departue){
    int n=arrival.size(), count=0;

    unordered_map<int, pair<int, int>>mpp;

    for(int i=0; i<n; i++){
        mpp[i] = {arrival[i], departue[i]};
    }

    sort(mpp.begin(), mpp.end(), comparator);

    n=mpp.size();

    mpp.erase(0);

    while(!mpp.empty()){
        for(int i=1; i<n; i++){
            if(mpp[i].)
        }
    }
}

int main(){

}