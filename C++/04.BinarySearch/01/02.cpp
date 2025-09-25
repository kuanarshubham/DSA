// first and last occurance

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Brute = O(n) -> iterate over the whole array
// Best1 = O(2logn) -> use UB & LB
// Best2 = O(2logn) -> custom fn

pair<int, int>firstAndLast(vector<int>&arr, int target){
    int l=0, r=arr.size()-1;
    int last = r+1, first = -1;

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]==target){
            first = mid;
            r=mid-1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    if(first == -1) return {-1, -1};

    l=0, r=arr.size()-1;

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]==target){
            last = mid;
            l=mid+1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return {first, last};
}

int main(){
    vector<int>arr1 = {5, 7, 7, 8, 8, 10}, arr2 = {5, 7, 7, 8, 8, 10};

    cout<<firstAndLast(arr1, 6).second<<" "<<firstAndLast(arr2, 8).second;
}