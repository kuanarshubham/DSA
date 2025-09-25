// serach in a rotated array 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&arr, int target){
    int l=0, r=arr.size()-1;
    int ans = r+1;

    while(l<=r){
        int mid = (l+r)/2;
        
        if(arr[mid]==target) return mid;
        else if(arr[mid] < arr[r]){
            if(arr[mid] <= target && target <=arr[r]){
                l=mid+1;
            }
            else r=mid-1;
        }
        else{
            if(arr[l]<=target && target<=arr[mid]){
                r=mid-1;
            }
            else l=mid+1;
        }
    }

    return -1;
}

int main(){
    
}