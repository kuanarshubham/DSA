// remove k digits

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string optimal(string s, int k){
    int n=s.size();

    if(n==k) return "0";

    stack<char>st;

    for(int i=0; i<n; i++){
        while(k>0 && !st.empty() && (s[i]-'0') < (st.top() - '0')){
            st.pop();
            k--;
        }

        st.push(s[i]);
    }

    string ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int countZeros=0;
    for(int i=0; i<ans.size(); i++){
        if(ans[i] == '0') countZeros++;
    }

    ans = ans.substr(countZeros);

    if(ans.size()>n-k) return ans.substr(0, n-k);

    return ans;
}

int main(){

}