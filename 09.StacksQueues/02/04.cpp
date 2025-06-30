// prefix to infix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// start from end
// top1 + top2

string preToIn(string s){
    int n=s.size(), i=n-1;
    stack<string>st;

    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else{
            string top1="", top2="";
            if(!st.empty() && st.size()>=2){
                top1 = st.top();
                st.pop();
                top2 = st.top();
                st.pop();
            }

            string newS = "(" + top1 + s[i] + top2 + ")";
            st.push(newS);
        }

        i--;
    }

    return st.top();
}

int main(){
    
}