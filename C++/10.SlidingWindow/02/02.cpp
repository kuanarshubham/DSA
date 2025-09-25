// a subarray with k digferent integers

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&v, int k){
    int n=v.size(), count=0;
    unordered_map<int, int>mpp;

    for(int i=0; i<n; i++){
        mpp.clear();
        for(int j=i; j<n; j++){
            mpp[v[j]]++;

            if(mpp.size() > k) break;

            if(mpp.size() == k) count++;
        }
    }

    return count;
}

int optimalHelper(vector<int>&v, int k){
    int n=v.size(), l=0, r=0, count=0;
    unordered_map<int, int>mpp;

    while(r<n){
        mpp[v[r]]++;

        if(mpp.size() > k){
            while(mpp.size() > k){
                mpp[v[l]]--;
                if(mpp[v[l]] == 0) mpp.erase(v[l]);
                l++;
            }
        }

        count += (r-l+1);
        r++;
    }

    return count;
}

int optimal(vector<int>&v, int k){
    return optimalHelper(v, k) - optimalHelper(v, k-1);
}

int main(){
    vector<int> v = {2, 1, 1, 1, 3, 4, 3, 2};
    
    cout<<brute(v, 3)<<" "<<optimal(v, 3);
}