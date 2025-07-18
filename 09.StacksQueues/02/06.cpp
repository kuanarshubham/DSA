// prefix to postfix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string preToPost(string s){
    int n=s.size(), i=n-1;
    stack<string>st;

    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else{
            string top1="", top2="";
            if(st.size()>=2){
                top1 = st.top();
                st.pop();
                top2 = st.top();
                st.pop();
            }

            string newS = top1 + top2 + s[i];
            st.push(newS);
        }

        i--;
    }

    return st.top();
}