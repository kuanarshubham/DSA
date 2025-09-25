// count subset with k sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(vector<int>&arr, int i, int target){
    if(target == 0) return 1;
    if(i==0){
        if(target == arr[i]) return 1;
        else return 0;
    }

    int take = 0; 
    if(arr[i]<=target) take = recc(arr, i-1, target-arr[i]);

    int notTake = recc(arr, i-1, target);

    return take + notTake;
}

int countSubset(vector<int>&arr, int target){
    int n=arr.size();
    return recc(arr, n-1, target);
}

int main(){
    vector<int>arr = {2, 3, 5, 16, 8, 10};
    cout<<countSubset(arr, 10);
}