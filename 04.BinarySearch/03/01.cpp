// row with max 1's

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<vector<int>>&matrix, int i){
    int n=matrix[i].size();
    int low=0, high=n-1, ans;

    while(low<=high){
        int mid=(low+high)/2;

        if(matrix[i][mid]>=1){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
}

int optimal(vector<vector<int>>&matrix){
    int n=matrix.size(), countMax=0, index=-1;
    for(int i=0; i<n; i++){
        int countCurr=lowerBound(matrix, i);

        if(countMax<countCurr){
            countMax=countCurr;
            index=i;
        }
    }

    return index;
}

int brute(vector<vector<int>>&matrix){
    int n=matrix.size(), m=matrix[0].size();

    int countMax=0, index=-1;

    for(int i=0; i<n; i++){
        int countOnes=0;
        for(int j=0; j<m; j++){
            countOnes++;
        }

        if(countMax<countOnes){
            countMax=countOnes;
            index=i;
        }
    }

    return index;
}

int main(){
    
}