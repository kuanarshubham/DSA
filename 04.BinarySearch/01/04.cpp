// search in roatted array with dups 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&arr, int target){
    int l=0, r=arr.size()-1;

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]==target) return mid;

        while(arr[l]==arr[mid] && arr[mid]==arr[r]){
            l=l+1;
            r=r-1;
        }

        if(arr[l]<=arr[mid]){
            if(arr[l]<=target && target<=arr[mid]){
                r=mid-1;
            }
            else l=mid+1;
        }
        else {
            if(arr[mid] <= target && target <=arr[r]){
                l=mid+1;
            }
            else r=mid-1;
        }
    }

    return -1;
}

int main(){

}