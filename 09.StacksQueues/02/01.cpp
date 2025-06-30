// infix to postfix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string postfixValue(string s){
    int n=s.size(), i=0;
    string ans="";
    stack<char>st;

    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }

            st.pop();
        }
        else{
            while(!st.empty() && priority(st.top())>=priority(s[i])){
                ans+=st.top();
                st.pop();
            }

            st.push(s[i]);
        }

        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string s = "(p+q)*(m-n)";
    cout<<postfixValue(s);
}