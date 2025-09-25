// min num of opetion (insertion and deletion)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int optimal(string s1, string s2){
    int n1=s1.size(), n2=s2.size();

    vector<int>prev(n2+1, 0), curr(n2+1, 0);

    for(int idx1=0; idx1<n1; idx1++){
        for(int idx2=0; idx2<n2; idx2++){
            
            if(s1[idx1] == s2[idx2]) curr[idx2] = 1+prev[idx2-1];
            else{
                int firstString = prev[idx2];
                int secondString = curr[idx2-1];
                curr[idx2] = max(firstString, secondString);
            }
        }

        prev = curr;
    }

    int lenLCS = prev[n2];

    return (n1+n2 - (2*lenLCS));
}