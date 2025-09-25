// heapify

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// max heap
void helper(vector<int>&v, int i){
    int leftI = 2*i, rightI = (2*i)+1, I = i;

    if(leftI < v.size() && v[leftI] > v[I]) I = leftI;
    
    if(rightI < v.size() && v[rightI] > v[I]) I = rightI;

    if(i != I){
        swap(v[i], v[I]);
        helper(v, I);
    }
}

void heapify(vector<int>&v){
    int n=v.size();
    
    for(int i=n/2; i>0; i--){
        helper(v, i);
    }

    for(auto it: v) cout<<it<<" ";
}

int main(){
    vector<int>v = {0, 2, 4, 5, 6, 88, 9};

    heapify(v);
}