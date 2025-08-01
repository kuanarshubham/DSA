// kth element of 2 sorted array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthValue(vector<int>&arr1, vector<int>&arr2, int k){
    int n1=arr1.size(), n2=arr2.size();

    if(n1>n2) return kthValue(arr2, arr1, k);

    int n=n1+n2;
    int left=k;
    int low=max(k-n2, 0), high=min(n2, k);

    while(low<=high){
        int mid1=(low+high)>>2;
        int mid2=left-mid1;

        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if(mid1<n1) r1=arr1[mid1];
        if(mid2<n2) r2=arr2[mid2];
        if(mid1-1>0) l1=arr1[mid1-1];
        if(mid2-1>0) l2=arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        } 
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }

    return 0;
}

int main(){

}