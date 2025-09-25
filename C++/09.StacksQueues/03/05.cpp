// sum of subarry min

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>pse(vector<int>&arr){
    int n=arr.size();
    vector<int>pseArray(n, -1);
    stack<int>st;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }

        pseArray[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pseArray;
}

vector<int>nse(vector<int>&arr){
    int n=arr.size();
    vector<int>nesArray(n, -1);
    stack<int>st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }

        nesArray[i]=st.empty() ? n : st.top();
        st.push(i);
    }

    return nesArray;
}

int sumOfSubArray(vector<int>&arr){
    int sum=0, n=arr.size();

    vector<int>prev = pse(arr), nxt = nse(arr);

    for(int i=0; i<n; i++){
        sum += arr[i] * (i - prev[i]) * (nxt[i] - i);
    }

    return sum;
}

int main(){

}