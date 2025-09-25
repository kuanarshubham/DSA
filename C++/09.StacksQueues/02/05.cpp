// postfix to prefix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


string postToPre(string s){
    int n=s.size(), i=0;
    stack<string>st;

    while(i<n){
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

            string newS = s[i] + top2 + top1;
            st.push(newS);
        }

        i++;
    }

    return st.top();
}

int main(){

}