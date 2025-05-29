// find the number that appears odd number of times

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int oddValue(vector<int>&arr){
    int xorVal = 0;

    for(auto it: arr) xorVal = xorVal ^ it;

    return xorVal;
}

int main(){
    vector<int> arr = {2, 4, 5, 2, 1, 6, 6, 4, 5};
    
    cout<<oddValue(arr);
    
}