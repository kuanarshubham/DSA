// nge 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>nge(vector<int>&arr){
    int n=arr.size();

    vector<int>ans(n, -1);
    stack<int>st;

    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && st.top()<arr[i%n]){
            st.pop();
        }

        if(i<n){
            ans[i] = st.empty()? -1 : st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

void printStack(stack<int>st){
    cout<<"Stack:"<<" ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();

    vector<int>ans(n, -1);
    stack<int>st;

    for(int i=n-1; i>=0; i--) st.push(arr[i]);

    printStack(st);

    for(int i=n-1; i>=0; i--){
        if(st.top()>arr[i]){
            ans[i]=st.top();
        }
        else{
            while(!st.empty() && st.top()<=arr[i]) st.pop();

            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
        }

        st.push(arr[i]);
        printStack(st);
    }

    return ans;
    }


int main(){
    vector<int>arr = {1, 2, 3, 4, 3};
    nextGreaterElements(arr);
}