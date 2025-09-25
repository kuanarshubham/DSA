// mini difference

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minDiff(vector<int>&arr){
    int rows=arr.size(), target=0;

    for(int i=0; i<rows; i++) target += arr[i];
    vector<bool>prev(target+1, false), temp(target+1, false);

    prev[0] = true;
    if(arr[0]<target+1) prev[arr[0]] = true;

    for(int idx=1; idx<rows; idx++){
        for(int t=1; t<target+1; t++){
            bool take = false;
            if(arr[idx]<=t) take = prev[t-arr[idx]];

            bool notTake = prev[t];

            temp[t] = take or notTake;
        }

        prev = temp;
    }

    vector<int>newArr;
    for(int i=0; i<=target; i++) if(prev[i]) newArr.push_back(i);

    int miniDiff = 1e8;

    for(auto it: newArr) miniDiff = min(miniDiff, abs(2*it - target));

    return miniDiff;
}

int main(){
    vector<int>arr = {3, 1, 6, 2, 2};
    cout<<minDiff(arr);
}