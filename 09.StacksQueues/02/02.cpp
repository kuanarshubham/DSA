// infix to prefix

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string infixToPrefix(string s){
    int n=s.size(), i=0;
    string ans="";
    stack<char>st;

    reverse(s.begin(), s.end());

    // ( -> )
    // ) -> (

    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]==')') st.push('(');
        else if(s[i]=='('){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }

            st.pop();
        }
        else{
            if(s[i]=='^'){
                
            }
        }

        i++;
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    string s = "a^b^c";
    cout<<infixToPrefix(s);
}