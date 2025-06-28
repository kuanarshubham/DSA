// meadian of 2 sorted array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int medianBrute(vector<int>&arr1, vector<int>&arr2){
    int n1=arr1.size(), n2=arr2.size(), i=0, j=0;
    vector<int>v3;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            v3.push_back(arr1[i]);
            i++;
        }
        else{
            v3.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n1){
        v3.push_back(arr1[i]);
        i++;
    }

    while(j<n2){
        v3.push_back(arr2[j]);
        j++;
    }

    int len = n1+n2;

    if(len%2==0) return (v3[len/2-1]+v3[len/2])/2;
    
    return v3[len/2];
}

int medianBetter(vector<int>&arr1, vector<int>&arr2){
    int n1=arr1.size(), n2=arr2.size(), i=0, j=0, mid1, mid2;
    int idx=(n1+n2)/2, count=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(idx-1==count) mid1 = arr1[i];
            if(idx==count) mid2 = arr1[i];
            count++;
            i++;
        }
        else{
            if(idx-1==count) mid1 = arr2[j];
            if(idx==count) mid2 = arr2[j];
            count++;
            j++;
        }
    }

    while(i<n1){
        if(idx-1==count) mid1 = arr1[i];
        if(idx==count) mid2 = arr1[i];
        count++;
        i++;
    }

    while(j<n2){
        if(idx-1==count) mid1 = arr2[j];
        if(idx==count) mid2 = arr2[j];
        count++;
        j++;
    }

    if((n1+n2)%2==0) return (mid1+mid2)/2;
    
    return mid2;
}

int medianOptimal(vector<int>&arr1, vector<int>&arr2){
    
}

int main(){

}