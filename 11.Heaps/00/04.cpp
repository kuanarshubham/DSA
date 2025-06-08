// heap sort

// build heap
// swap(1, n-1)
// heapify(1 -> i)
// sorting from last onwards

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v, int i, int n){
    int p=i, c1=(2*i), c2=(2*i)+1;

    if(c1<n && v[p] < v[c1]) p=c1;

    if(c2<n && v[p] < v[c2]) p=c2;

    if(p != i){
        swap(v[p], v[i]);
        heapify(v, p, n);
    }

    return;
}

void heapSort(vector<int>&arr){
    int n=arr.size(), i=0;

    for(int i=n/2; i>0; i--){
        heapify(arr, i, n);
    }

    for(int i=n-1; i>0; i--){
        swap(arr[1], arr[i]);
        heapify(arr, 1, i);
    }

    for(auto it: arr) cout<<it<<" ";
}

int main(){
    vector<int>v = {-1, 4, 1, 22, 33, 5, 0, 18};

    heapSort(v);
}