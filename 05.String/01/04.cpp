// longest common prefix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(vector<string>&arr){
    int n=arr.size();

    sort(arr.begin(), arr.end());
    int firstWord = arr[0].size();

    int count=0;
    for(int i=0; i<firstWord; i++){
        if(arr[0][i] == arr[n-1][i]) count++;
        else break;
    }

    return arr[0].substr(0, count);
}