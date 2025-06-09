// check if array rep min or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isMinHeap(vector<int>&v){
    int i=0, n=v.size();

    while(i<n-1){
        if(v[i] < v[i+1]) return true;
        i++;
    }

    return false;
}

int main(){
    vector<int>v = {1, 2, 3, 4, 5, 6};

    cout<<isMinHeap(v);
}