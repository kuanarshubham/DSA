// Longest Palindromic Substring[Do it without DP]

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string optimal(string s){
    int n =s.size(), resLen=0;
    string ans="";

    // from middle you will go towarsd bothe sides, simunltaneouly
    // that way, it is possible for me to take odd lenght string
    // to get into even lenght, move one ahead of other

    for(int i=0; i<n; i++){

        int l=i, r=i;
        string prefix="";
        while(l>=0 && r<n && s[l]==s[r]){
            prefix=s[l]+prefix+s[r];
            if(r-l+1 > resLen){
                resLen = r-l+1;
                ans = prefix;
            }
            l--;
            r++;
        }

        
        if(i<n-1){
            l=i, r=i+1;
            string prefix="";
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                prefix=s[l]+prefix+s[r];
                if(resLen<r-l+1){
                    resLen=r-l+1;
                    ans=prefix;
                }
                r++;
                l--;
            }
        }
    }

    return ans;
}