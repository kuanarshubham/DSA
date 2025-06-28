// Book Allocation

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>&pages, int maxPages){
    int currStudent=1, currPages=0, n=pages.size();

    for(int i=0; i<n; i++){
        if(currPages+pages[i]>maxPages){
            currStudent++;
            currPages=pages[i];
        }
        else currPages+=pages[i];
    }

    return currStudent;
}

int minMaxPages(vector<int>&pages, int students){
    int n=pages.size(), maxArray=INT_MIN, sum=0;

    for(int i=0; i<n; i++){
        maxArray = max(maxArray, pages[i]);
        sum+=pages[i];
    }

    // this range is for maximum pages one can have
    int l=maxArray, r=sum, ans=0;

    while(l<=r){
        int mid=(l+r)/2; // max number of pages

        int possibleStudent = isPossible(pages, mid);

        if(possibleStudent == students) ans = mid;
        else if(possibleStudent > students) l=mid+1;
        else r=mid-1;
    }

    return ans; // return low gives same ans;
}

int main(){

}