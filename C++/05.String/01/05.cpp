// isomorphic strings

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool brute(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    if(n1!=n2) return false;

    unordered_map<char, char>s1Tos2, s2Tos1;

    for(int i=0; i<n1; i++){
        if(s1Tos2.find(s1[i])==s1Tos2.end() && s2Tos1.find(s2[i])==s2Tos1.end()){
            s1Tos2[s1[i]] = s2[i];
            s2Tos1[s2[i]] = s1[i];
        } 
        else return false;
    }

    return true;
}

bool optimla(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    if(n1!=n2) return false;

    vector<int>index1(200, 0), index2(200, 0);

    for(int i=0; i<n1; i++){
        if(index1[s1[i]] != index2[s2[i]]) return false;
        
        index1[s1[i]] = i+1;
        index2[s2[i]] = i+1;
    }

    return true;
}