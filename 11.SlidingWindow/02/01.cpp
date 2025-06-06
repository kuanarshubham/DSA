// Longest Substring with At Most K Distinct Characters

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestSubstringBrute(string s, int k){
    int n = s.size(), maxLen = 0, stratIdx = 0;

    for(int i=0; i<n; i++){
        set<char>schar;

        for(int j=i; j<n; j++){
            schar.insert(s[j]);

            if(schar.size() <= k){
                if(maxLen < j-i+1){
                    stratIdx = i;
                    maxLen = j-i+1;
                }
            }
            else break;
        }
    }

    

    return s.substr(stratIdx, maxLen);
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

string longestSubstringOptimal(string s, int k){
    int n = s.size(), maxLen = 0, startIdx = 0, r = 0, l = 0;

    unordered_map<int, int>mpp;

    while(r<n){
        mpp[s[r]]++;

        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }

        if(maxLen < r-l+1){
            maxLen = r-l+1;
            startIdx = l;
        }

        r++;
    }

    return s.substr(startIdx, maxLen);
}


int main(){
    string s = "aabcddeefgggg";
    cout<<longestSubstringBrute(s, 3)<<" "<<longestSubstringBetter(s, 3)<<" "<<longestSubstringOptimal(s, 3);
}