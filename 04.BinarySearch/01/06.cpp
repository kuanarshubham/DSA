// find out the number of time the arry is roatted

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numbberTimesRotated(vector<int>&arr){
    int l=0, r=arr.size()-1, mini=INT_MAX;

    while(l<=r){
        int mid = (l+r)/2;

        if(arr[l]<=arr[mid]){
            mini=min(mini, arr[l]);
            l=mid+1;
        }
        else{
            mini = min(mini, arr[mid]);
            r=mid-1;
        }
    }

    return mini;
}

int main(){

}