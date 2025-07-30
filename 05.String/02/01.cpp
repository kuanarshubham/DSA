// sort the string based on frequncy

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(string s){

    vector<int>freq(128, 0);

    for(auto ch: s) freq[ch]++;

    auto cmp = [&](char a, char b){
        if(freq[a]==freq[b]) return  a<b;
        return freq[a]>freq[b];
    };

    sort(s.begin(), s.end(), cmp);

    return s;
}

string better(string s){
    unordered_map<char, int>mpp;
    for(auto ch: s)mpp[ch]++;

    set<pair<int, char>>freq;
    for(auto it: mpp) freq.insert({it.second, it.first});

    int setSize = freq.size();
    string ans="";
    for(auto it: freq){
        ans.append(it.first, it.second);
    }
    
    return ans;
}

string optimal(string s){
    unordered_map<char,int>mpp;
    for(auto ch: s) mpp[ch]++;

    vector<vector<char>>bucketData(s.length()+1);
    for(auto it: mpp) bucketData[it.first].push_back(it.second);

    string ans="";
    for(int fq=s.length(); fq>=1; fq--){
        for(auto ch: bucketData[fq]) ans.append(ch, fq);
    }

    return ans;
}