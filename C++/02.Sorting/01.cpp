// selection sorting

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    int n=arr.size();

    for(int i=0; i<n-1; i++){
        int mini = i;

        for(int j=i; j<n; j++){
            if(arr[j]<arr[mini]) mini = j;
        }

        swap(arr[mini], arr[i]);
    }

    for(auto it: arr) cout<<it<<" ";
}