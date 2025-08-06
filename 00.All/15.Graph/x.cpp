#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMaxi(vector<int>&nums){
    int n=nums.size(), maxi = INT_MIN;

    for(int i=1; i<n; i++){
        for(int arri=1; arri<nums[i]; arri++){
            int localMaxi = INT_MIN;

            for(int j=0; j<n; j++){
                if(i==j){
                    localMaxi = max(localMaxi, nums[j]-arri);
                }
                else if(j==i-1){
                    localMaxi = max(localMaxi, nums[j]+arri);
                }
                else{
                    localMaxi = max(localMaxi, nums[i]);
                }
            }

            maxi = min(localMaxi, maxi);
        }
    }

    return maxi;
}

int main(){

}