// anagram

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool brute(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    if(n1!=n2) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1==s2;
}

bool better(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    if(n1!=n2) return false;

    vector<int>hash(26, 0);

    for(int i=0; i<n1; i++){
        hash[s1[i] - (int)'a']++;
        hash[s2[i] - (int)'a']--;
    }

    for(int i=0; i<26; i++){
        if(hash[i]!=0) return false;
    }

    return true;
}

