// longest string chain 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compareStrings(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    if(n1>n2 || n2-n1!=1) return false;

    int i=0, j=0;
    while(i<n1){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    return (i==n1 && j==n2);
}

int spaceopt(vector<string>&s){
    int n=s.size();

    vector<int>ahead(n+1, 0), curr(n+1, 0);

    sort(s.begin(), s.end(), [](string &s1, string &s2){
        return s1.length() < s2.length();
    });

    for(int idx=n-1; idx>=0; idx--){
        for(int prev=idx-1; prev>=-1; prev--){
            int notTake = ahead[prev+1], take=0;

            if(prev==-1 || compareStrings(s[prev], s[idx])) take = 1 + ahead[prev+1];

            curr[prev+1] = max(take, notTake);
        }

        ahead=curr;
    }

    return ahead[0];
}