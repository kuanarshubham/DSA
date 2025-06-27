// Capacity to Ship Packages within D Days

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int reqTime(vector<int>weight, int capacity){
    int dayCount=1, load=0, n=weight.size();

    for(int i=0; i<n; i++){
        if(load+weight[i]>capacity){
            dayCount++;
            load=0;
        }
        load+=weight[i];
    }

    return dayCount;
}


int capacityMin(vector<int>&weight, int days){
    int n=weight.size(), maxArray=INT_MIN, sum=0;

    for(int i=0; i<n; i++){
        maxArray=max(maxArray, weight[i]);
        sum+=weight[i];
    }

    int l=maxArray, r=sum, ans=0;

    while(l<=r){
        int mid=(l+r)/2;

        int daysReq = reqTime(weight, mid);

        if(daysReq<=days){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return ans;
}

int main(){

}