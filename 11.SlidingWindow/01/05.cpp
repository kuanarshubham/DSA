// max consicuteive 1, given k switches of 0 to 1 can be done to get the maxLen
// this ques -> convberted to, maxLen(subarray) with k zeros

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// brute 
// geneate all possible subarrays
// O(N^2)
int maxLen1WithkZerosBrute(vector<int>&v, int k){
    int maxLen = 0, n = v.size();

    for(int i=0; i<n; i++){
        int zeros = 0;
        for(int j=i; j<n; j++){
            if(v[j] == 0) zeros++;

            if(zeros > k) break;
            else{
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    return maxLen;
}


// better
// window use
// (zeros > k) -> l++ till zero == k
// O(2N)
int maxLen1WithkZerosBetter(vector<int>&v, int k){
    int n = v.size(), l =0, r = 0, maxLen = 0, zeros = 0;

    while(r<n){
        if(v[r] == 0) zeros++;

        while(zeros>k){
            if(v[l] == 0) zeros--;
            l++;
        }

        if(zeros <= k) maxLen = max(maxLen, r-l+1);

        r++;
    }

    return maxLen;
}


// Optimal
// once maxLen is fixed we'll only expand the window
// O(N)
int maxLen1WithkZerosOptimal(vector<int>&v, int k){
    int n = v.size(), l =0, r = 0, maxLen = 0, zeros = 0;

    while(r<n){
        if(v[r] == 0) zeros++;

        if(zeros>k){
            if(v[l] == 0) zeros--;
            l++;
        }

        if(zeros <= k) maxLen = max(maxLen, r-l+1);

        r++;
    }

    return maxLen;
}

int main(){
    vector<int> v = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    cout<<maxLen1WithkZerosBrute(v, 2)<<" "<<maxLen1WithkZerosBetter(v, 2)<<" "<<maxLen1WithkZerosOptimal(v, 2);
}