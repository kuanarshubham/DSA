// Binary Subarrays With Sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int noOfArraysWithGoalBrute(vector<int>&v, int goal){
    int n=v.size(), count=0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += v[j];
            
            if(sum == goal) count++;
            
            if(sum > goal) break;
        }
    }

    return count;
}

int helperBetter(vector<int>&v, int goal){
    if(goal <  0) return  0;

    int n=v.size(), count=0, l=0, r=0, sum=0;

    while(r<n){
        sum+=v[r];
        
        if(sum > goal){
            while(sum > goal){
                sum-=v[l];
                l++;
            }
        }

        count += (r-l+1);
        r++;
    }

    return count;
}

int noOfArraysWithGoalOptimal(vector<int>&v, int goal){
    return helperBetter(v, goal) - helperBetter(v, goal-1);
}

int main(){
    vector<int> v = {0, 0, 0, 0, 1};
    cout<<noOfArraysWithGoalBrute(v, 0)<<" "<<noOfArraysWithGoalOptimal(v, 0);
}