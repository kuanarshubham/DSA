// remove oter paranetattes

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(string s){
    int n=s.size();

    stack<char>st;
    string ans = "";

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            if(!st.empty()) ans+='(';
            st.push('(');
        }
        else{
            st.pop();
            if(!st.empty()) ans+=')';
        }
    }

    return ans;
}

string optimal(string s){
    int n=s.size(), count=0;

    string ans="";

    for(int i=0; i<n; i++){
        if(s[i]=='('){
            if(count!=0) ans+='(';
            count++;
        }
        else{
            count--;
            if(count!=0) ans+=')';
        }
    }
    return ans;
}

int main(){
    string s = "(()())(())";

    cout<<brute(s)<<" "<<optimal(s);
}