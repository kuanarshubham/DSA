// is a heap or not (max heap)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isHeap(vector<int>&v, int i, int n){
    if(i>=n) return true;

    int c1=i*2+1, c2=i*2+2;

    if(c1<n && v[c1]>v[i]) return false;
    if(c2<n && v[c2]>v[i]) return false;
    
    bool left = isHeap(v, c1, n);
    bool right = isHeap(v, c2, n);

    return left && right;
}

bool isMaxHeap(vector<int>&v){
    return isHeap(v, 0, v.size());
}

int main(){
    vector<int>v = {6, 4, 3, 2, 1};

    cout<<isMaxHeap(v);
}