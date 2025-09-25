// bubble sort

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>brute(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

    return arr;
}

vector<int>optimal(vector<int>arr){
    int n=arr.size();

    for(int i=0; i<n-1; i++){
        int swapTimes = 0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }

        if(swapTimes==0) return arr;
    }
}

int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    
    
    vector<int>ans = brute(arr);
    vector<int>ansOptimal = optimal(arr);

    for(auto it: ansOptimal) cout<<it<<" ";
}