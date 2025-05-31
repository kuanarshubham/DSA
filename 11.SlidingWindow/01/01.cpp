// constant window size, find max sum of subarray

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//brute
//  maxSum = 0;
//  ans[]
//  for(i = 0 -> n-4)
//      sum = 0
//      temp[]
//      for(j = i -> j+window)
//          sum += arr[j]
//      if(maxSum != sum) ans = temp;
//      maxSum = max(sum, maxSum)
//  return maxSum, ans


//optimal
int maxSubarraySum(vector<int>&arr, int window){
    int n = arr.size();
    
    int r = window-1, l = 0;
    int maxSum = 0;

    for(int i=0; i<window; i++){
        maxSum += arr[i];
    }

    cout<<maxSum<<" ";

    while(r<n-1){
        int sum = maxSum - arr[l];
        l++;
        r++;
        sum += arr[r];

        cout<<sum<<" ";
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    int window = 4;

    cout<<maxSubarraySum(arr, window);

    return 0;
}