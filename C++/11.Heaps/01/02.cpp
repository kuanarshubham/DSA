// convert min heap to max heap

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v, int i, int n){
    int c1 = i*2+1, c2 = i*2+2, p=i;

    if(c1 < n && v[c1] > v[p]) p=c1;

    if(c2 < n && v[c2] > v[p]) p=c2;

    if(p != i){
        swap(v[p], v[i]);
        heapify(v, p, n);
    }
}

void buildMaxHeap(vector<int>&v){
    int n =v .size();

    for(int i=(n-2)/2; i>=0; i--){
        heapify(v, i, n);
    }

    for(auto it: v) cout<<it<<" ";
}

int main(){
    vector<int>v = {4, 7, 9, 12, 24, 30, 18};

    buildMaxHeap(v);
}