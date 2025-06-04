// Longest Substring with At Most K Distinct Characters

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestSubstringBrute(string s, int k){
    int n = s.size(), maxLen = 0;
    string ans="";

    for(int i=0; i<n; i++){
        set<char>schar;
        string temp = "";
        for(int j=i; j<n; j++){
            schar.insert(s[j]);

            if(schar.size() > k){
                if(temp.size() > ans.size()){
                    ans = temp;
                }

                temp = "";
                break;
            }
            
            if(maxLen < j-i+1){
                maxLen = j-i+1;
                temp.push_back(s[j]);
            }
        }
    }

    return ans;
}

string longestSubstringBetter(string s, int k){
    int n=s.size(), l=0, r=0, maxLen = 0, stratIdx =0;

    map<int, int> mpp;

    while(r<n){
        mpp[s[r]]++;

        if(mpp.size()>k){

            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
        }

        if(r-l+1 > maxLen){
            maxLen = r-l+1;
            stratIdx = l;
        }

        r++;
    }

    return s.substr(stratIdx, maxLen);
}


int main(){
    string s = "abcddefg";
    cout<<longestSubstringBrute(s, 3)<<" "<<longestSubstringBetter(s, 3);
}