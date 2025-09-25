// nice subarray

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int helperFn(vector<int>&v, int goal){
    if(goal<0) return 0;

    int n=v.size(), l=0, r=0, count=0, sum=0;

    while(r<n){
        sum+=v[r];

        while(sum > goal){
            sum-=v[l];
            l++;
        }

        count+=(r-l+1);
        r++;
    }

    return count;
}

int niceArray(vector<int>&v, int k){
    vector<int>newV;

    for(auto it: v) newV.push_back(it%2);

    return helperFn(newV, k) - helperFn(newV, k-1);
}

int main(){
    vector<int>v = {7, 2, 5, 4, 1, 9};

    cout<<niceArray(v, 2);
}