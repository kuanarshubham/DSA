// check if array rep min or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>&v, int i, int n){

    int c1 = i*2+1, c2=i*2+2;

    if(c1 < n && v[c1] < v[i]) return false;
    if(c2 < n && v[c2] < v[i]) return false;

    int left = isMinHeap(v, c1, n);
    int right = isMinHeap(v, c2, n);

    
}

int main(){
    vector<int>v = {1, 2, 3, 4, 5, 6};

    cout<<isMinHeap(v);
}