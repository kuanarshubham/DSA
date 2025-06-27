// nth root

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fn(int mid, int power, int n){
    int val = 1;

    for(int i=1; i<=power; i++){
        if(val>n) return 2;
        val*=val;
    }

    if(val==n) return 1;
    return 3;
}

int nth_rtMine(int n, int expo){
    int l=1, r=n, ans=0;

    while(l<=r){
        int mid=(l+r)/2;

        int val=fn(mid, expo, n);
        if(val==1) return mid;
        else if(val==2) r=mid-1;
        else{
            ans = mid;
            l=mid+1;
        }
    }

    return ans;
}

int main(){
    
}