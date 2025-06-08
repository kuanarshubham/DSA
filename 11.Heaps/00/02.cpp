// deletion from heap -> means delet the root  node

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// max heap
void deletion(vector<int>&v){
    int n=v.size(), i=1;

    if(n==0) return;

    v[1] = v[n-1];
    v.pop_back();

    while(i<n){
        int leftChild = 2*i, rightChild = (2*i)+1;

        int comparingChild = v[leftChild] > v[rightChild] ? leftChild : rightChild;

        if(v[i] < v[comparingChild]){
            swap(v[i], v[comparingChild]);
            i=comparingChild;
        }
        else return;
    }

    for(auto it: v) cout<<it<<" ";
}

int main(){
    vector<int>v = {0, 50, 40, 44, 30, 35, 42, 20};

    deletion(v);
}