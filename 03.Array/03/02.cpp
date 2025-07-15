// n/3 majority

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n2majority(vector<int>&arr){
    int ele=arr[0], count=0, n=arr.size();

    for(int i=0; i<n; i++){
        if(count==0){
            ele=arr[i];
        }
        
        if(arr[i]==ele) count++;
        else count--;
    }

    count=0;
    for(int i=0; i<n; i++){
        if(arr[i]==ele) count++;
    }

    if(count>floor(n/2)) return ele;
    
    return -1;
}

vector<int> n3Majority(vector<int>&arr){
    int n=arr.size(), ele1=arr[0], ele2=arr[0], count1=0, count2=0;

    for(int i=0; i<n; i++){
        if(count1<=0 && ele2!=arr[i]){
            ele1=arr[i];
        }
        else if(count2<=0 && ele1!=arr[i]){
            ele2=arr[i];
        }
        else if(arr[i]==ele1) count1++;
        else if(arr[i]==ele2) count2++;
        else {
            count1--;
            count2--;
        }
    }

    return {ele1, ele2};
}

int main(){}