// longest substring without repaeting character

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// brute 
// generate all subStrings non repeative and find the largest
// TC = O(N * N * N)
// Sc = O(N)
bool nonRepeative(string s){
    unordered_set<char> s1(s.begin(), s.end());
    return s.size() == s1.size();
}


string longestStringBrute(string s ){
    string ans = "";

    for(int i=0; i<s.size(); i++){
        string temp = "";
        for(int j=i; j<s.size(); j++){
            temp += s[j];
            if(nonRepeative(temp)){
                if(ans.size() < temp.size()) ans = temp;
            }
            else break;
        }
    }

    return ans;
}


// better 
// use a hash map of 255 size

string longestStringBetter(string s){
    string ans = "";

    int n = s.size();
    for(int i=0; i<n; i++){

        string temp = "";
        int hash_arr[256] = {0};
        
        for(int j=i; j<n; j++){
            if(hash_arr[int(s[j])] == 1) break;

            temp += s[j];
            hash_arr[int(s[j])] = 1;

            if(ans.size() < temp.size()) ans = temp;
        }
    }

    return ans;
}

string longestStringOptimal(string s){
    int n = s.size(), l=0, r = 0;

    string ans, temp;
    int hash[256] = {-1};

    while(r<n){
        if(hash[int(s[r])] >= 0){
            if(hash[int(s[r])] > l) l = l + 1;
        }
        
        temp += s[r];
        hash[int(s[r])] = r;

        if(ans.size() < temp.size()) ans = temp;
        cout<<hash[int(s[r])];
        r++;
        


    }

    return ans;
}

int main(){
    string s =  "aaabbbccc";
    cout<<longestStringBrute(s)<<" "<<longestStringBetter(s)<<" "<<longestStringOptimal(s)<<endl;
}