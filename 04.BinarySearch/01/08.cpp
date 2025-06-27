// peak of array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>&arr){
    int n=arr.size();
    int l=1, r=n-1;

    if(n==1) return arr[0];
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    while(l<=r){
        int mid=(l+r)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;

        if(arr[mid]>arr[mid-1]) l=mid+1;
        else if(arr[mid]>arr[mid-1]) r=mid-1;
    }
}

int main(){

}