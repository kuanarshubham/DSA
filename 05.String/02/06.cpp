// sum of beauty of substrings

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int>getMax_MinFreq(string s){
    int n=s.size();

    vector<int>freq(128, 0);

    for(auto it: s) freq[it]++;

    int maxi=INT_MIN, mini=INT_MAX;
    char mini_char, maxi_char;

    for(int i=0; i<26; i++){
        if(freq[i]>0){
            if(freq[i]>maxi){
                maxi=freq[i];
                maxi_char=(char)i;
            }
            
            if(freq[i]<mini){
                mini=freq[i];
                mini_char=(char)i;
            }
        }
    }

    return {maxi, mini};
}

int brue(string s){
    int n =s.size();

    int beautySum=0;

    for(int i=0; i<n; i++){
        string subs = "";
        for(int j=i; j<n; j++){
            subs+=(s[j]);

            pair<int, int> x = getMax_MinFreq(subs);
            beautySum+=(x.first-x.second);
        }
    }

    return beautySum;
}

pair<int, int> getMin_Max_Optimal(vector<int>&freq){
    int maxi=INT_MIN, mini=INT_MAX;

    for(int i=0; i<26; i++){
        if(freq[i]!=0) mini = min(mini, freq[i]);
        maxi = max(maxi, freq[i]);
    }

    return  {maxi, mini};
}


int optimal(string s){
    int n=s.size();

    int sum=0;

    for(int i=0; i<n; i++){
        vector<int>freq(26, 0);
        for(int j=i; j<n; j++){
            int val=s[j]-(int)'a';
            freq[val]++;
            pair<int, int> it = getMin_Max_Optimal(freq);

            sum += (it.first - it.second);
        }
    }

    return sum;
}