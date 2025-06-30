#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printArrr(vector<int>&v){
    for(auto it: v) cout<<it<<" ";
    cout<<endl;
}

void nge(vector<int>&v){
    vector<int>ans;
    stack<int> st;
    for(int i=v.size()-1; i>=0; i--){
        
        while(!st.empty() && st.top()<=v[i]) st.pop();

        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());


        st.push(v[i]);
    }

    reverse(ans.begin(), ans.end());

    printArrr(ans);
}

void nse(vector<int> &v){
    vector<int>ans;
    stack<int> st;

    for(int i=v.size()-1; i>=0; i--){

        while(!st.empty() && st.top()>=v[i]) st.pop();

        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());

        st.push(v[i]);
    }

    reverse(ans.begin(), ans.end());

    printArrr(ans);
}

void pge(vector<int> &v){
    vector<int>ans;
    stack<int> st;

    for(int i=0; i<v.size(); i++){
        while(!st.empty() && st.top()<=v[i]) st.pop();

        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());

        st.push(v[i]);
    }

    printArrr(ans);
}

void pse(vector<int> &v){
    vector<int>ans;
    stack<int> st;

    for(int i=0; i<v.size(); i++){

        while(!st.empty() && st.top()>=v[i]) st.pop();

        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());

        st.push(v[i]);
    }

    printArrr(ans);
}


int main(){
    vector<int> v = {4, 5, 6, 1, 2, 1};
    printArrr(v);
    nge(v);
    nse(v);
    pge(v);
    pse(v);
}