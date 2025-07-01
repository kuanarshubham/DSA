// next greatest element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>nextGreatest(vector<int>&arr){
    int n=arr.size(), i=n-1;
    
    stack<int>st;
    st.push(arr[i]);
    i--;

    vector<int>ans(n, -1);
    ans[n-1]=-1;

    while(i>=0){
        int top=st.top();

        if(arr[i]<top){
            ans[i]=top;  
        }
        else{
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }

            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
        }

        st.push(arr[i]);
        i--;
    }

    
    
    return ans;
}

int main(){
    
}