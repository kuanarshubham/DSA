// aggresive cows

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&dist, int space, int cows){
    int n=dist.size(), prevCow=dist[0], cowsDone=1;

    for(int i=1; i<n; i++){
        if(dist[i]-prevCow >= space){
            prevCow=dist[i];
            cowsDone++;
        }
    }

    if(cowsDone >= cows) return true;
    
    return false;
}

int maxMinDistance(vector<int>&dist, int cows){
    int n=dist.size();

    sort(dist.begin(), dist.end());

    int l=1, r=dist[n-1]-dist[0], ans;

    while(l<=r){
        int mid=(l+r)/2; // mid = spaceBetween2Cows

        if(isPossible(dist, mid, cows)){
            ans=mid; 
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return ans; // also the 
}

int main(){

}