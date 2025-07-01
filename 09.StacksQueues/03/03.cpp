// nse

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>nse(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>ans(n, -1);

    st.push(arr[0]);

    for(int i=1; i<n; i++){
        if(st.top()<arr[i]){
            ans[i]=st.top();
        }
        else{
            while(!st.empty() && st.top()>arr[i]) st.pop();

            if(!st.empty()) ans[i]=st.top();
        }
    }

    return ans;
}

int main(){
    
}