// jump2 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(vector<int>&jumps, int i, int n, int count, int miniCount){
    if(i>=n-1){
        miniCount = min(miniCount, count);
        return miniCount;
    }

    for(int j=1; j<=jumps[i]; j++){
        miniCount = min(miniCount, recc(jumps, i+j, n, count+1, miniCount));
    }

    return miniCount;
}

int jumpsBrute(vector<int>&jumps){
    int n=jumps.size(), i=0, count=0, miniCount=INT_MAX;

    return recc(jumps, i, n, count, miniCount);
}

// for better go with dp

int jumpsOptimal(vector<int>&jumps){
    int n=jumps.size(), l=0, r=0, count=0;

    while(r<n-1){
        int farthest = 0;

        for(int i=l; i<=r; i++){
            farthest = max(farthest, i+jumps[i]);
        }

        l=r+1;
        r=farthest;
        count++;
    }

    return count;
}

int main(){
    vector<int>jumps = {4, 3, 1, 1, 2, 3, 4};

    cout<<jumpsBrute(jumps)<<" "<<jumpsOptimal(jumps);
}