// lower bound and upper bound

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&arr, int target){
    int l=0, r=arr.size()-1, ans=arr.size();

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]>=target){
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }

    return ans;
}

int upperBound(vector<int>&arr, int target){
    int l=0, r=arr.size()-1, ans=arr.size();

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]>target){
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int>arr = {3,5,8,15,19};
    cout<<lowerBound(arr, 8)<<" "<<upperBound(arr, 8);
}