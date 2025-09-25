// min no of platform

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// bool comparator(pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b){
//     return a.second.second < b.second.second;
// } 


int platformBrute(vector<int>arrival, vector<int>departue){

    // look for intersection of time

    int n=arrival.size(), maxCount=0;

    for(int i=0; i<n; i++){
        int count=1;

        for(int j=i+1; j<n; j++){
            bool condition = (arrival[i] < arrival[j] && departue[i] > departue[j]) || (arrival[i] > arrival[j] && departue[i] < departue[j]) || (arrival[i] < arrival[j] && departue[i] > departue[j]) || (arrival[i] > arrival[j] && departue[i] < departue[j]);

            if(condition) count++;
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int platformOptimal(vector<int>arrival, vector<int>departure){
    int n=arrival.size(), l=0, r=0, count=0, maxCount=0;

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    while(r<n && l<n){
        if(arrival[l] <= departure[r]){
            count++;
            l++; 
        }
        else if(arrival[l] > departure[r]){
            count--;
            r++;
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main(){
    vector<int>arrival = {900, 945, 955, 1100, 1500, 1800}, departure = {920, 1200, 1130, 1150, 1900, 2000};

    cout<<platformBrute(arrival, departure)<<" "<<platformOptimal(arrival, departure);
}