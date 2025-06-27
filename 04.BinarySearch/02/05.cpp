// Find the smallest Divisor

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calculateSum(vector<int>&nums, int val){
    int sum=0, n=nums.size();

    for(int i=0; i<n; i++){
        sum+=ceil((double)nums[i]/val);
    }

    return sum;
}

int minVal(vector<int>&nums, int limit){
    int n=nums.size(), maxVal=INT_MIN;

    for(int i=0; i<n; i++) maxVal = max(maxVal, nums[i]);

    int l=1, r=maxVal, ans=0;

    while(l<=r){
        int mid=(l+r)/2;

        int valCalulated=calculateSum(nums, mid);

        if(valCalulated<=limit){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }

    return ans;
}

int main(){

}