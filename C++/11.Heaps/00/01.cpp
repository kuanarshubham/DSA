#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//insertion
void insertion(vector<int>&arr, int x){
    arr.push_back(x);
    int curr_x = arr.size()-1;

    int maxHeap = arr[1] - arr[2];

    if(maxHeap>0){
        while(curr_x>=2){
            if(arr[curr_x/2] < arr[curr_x]) swap(arr[curr_x], arr[curr_x/2]);
            curr_x/=2;
        }
    }
    else{
        while(curr_x>=2){
            if(arr[curr_x/2] > arr[curr_x]) swap(arr[curr_x], arr[curr_x/2]);
            curr_x/=2;
        }
    }

    for(auto it: arr) cout<<it<<" ";
    cout<<endl;
}

int main(){
    vector<int>v = {0, 60, 50, 40, 30, 20};
    insertion(v, 55);
    insertion(v, 70);
}