// srqt of a number 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sqrtMine(int n){
    int l=1, r=n, ans=0;

    while(l<=r){
        int mid=(l+r)/2;

        int val=mid*mid;
        if(val==n) return mid;
        else if(val<n){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }

    return ans;
}

int main(){
    cout<<sqrtMine(200);
}