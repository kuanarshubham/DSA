// candies

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int candyBetter(vector<int>&r){
    vector<int>left;
    int n=r.size(), sum = 0;

    left.push_back(1);

    for(int i=1; i<n; i++){
        if(r[i] > r[i-1]) left.push_back(left[i-1]+1);
        else left.push_back(1);
    }

    left[n-1] = max(left[n-1], 1);

    sum+=left[n-1];

    for(int i=n-2; i>=0; i--){
        if(r[i] > r[i+1]) left[i] = max(left[i], left[i+1]+1);
        else left[i] = max(left[i], 1);

        sum+=left[i];
    }

    return sum;
}

int candyOptimal(vector<int>&rating){
    int n=rating.size(), i=1, sum=1;

    while(i<n){
        if(rating[i] == rating[i-1]){
            sum+=1;
            i++;
            continue;
        }

        int peak=1;

        while(i<n && rating[i] > rating[i-1]){
            peak++;
            sum+=peak;
            i++;
        }

        int down=1;

        while(i<n && rating[i] < rating[i-1]){
            sum+=down;
            i++;
            down++;
        }

        if(down > peak) sum += down-peak;
    }

    return sum;
}

int main(){
    vector<int>ratings={1,2,87,87,87,2,1};
    cout<<candyBetter(ratings)<< " "<<candyOptimal(ratings);
}