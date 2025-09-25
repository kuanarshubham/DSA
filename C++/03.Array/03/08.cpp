// merge 2 sorted array without using extra space

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void optimal1(vector<int>&arr1, vector<int>&arr2){
    int n=arr1.size(), m=arr2.size(), i=n-1, j=0;

    while(i>=0 && j<=m-1){
        if(arr1[i]>arr2[j]){
            swap(arr1[i], arr2[j]);
            i--; j++;
        }
        else break;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}


// shell sort method
void optimal2(vector<int>&arr1, vector<int>&arr2){
    
}

int main(){}