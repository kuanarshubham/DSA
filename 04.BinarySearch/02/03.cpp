// koko eating banana

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int calculateHrs(vector<int>&bananas, int speed){
    int hrs=0, n=bananas.size();
    
    for(int i=0; i<n; i++){
        hrs+=ceil((double)bananas[i] / speed);
    }

    return hrs;
}

int minNumbers(vector<int>&bananas, int hrs){
    int n=bananas.size(), maxVal=INT_MIN;

    for(int i=0; i<n; i++) maxVal=max(maxVal, bananas[i]);

    int l=1, r=maxVal, ans=0;

    while(l<=r){
        int mid = (l+r)/2;

        int hrsTaken = calculateHrs(bananas, mid);
        
        if(hrsTaken > hrs){
            l=mid+1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }

    return ans;
}


int main(){
    
}