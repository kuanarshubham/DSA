// power set

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>powerset(vector<int>&v){
    int n =  v.size();
    int subset = 1<<n;

    vector<vector<int>>ans;

    for(int i=0; i<subset; i++){
        vector<int>temp;
        for(int j=0; j<n; j++){
            if(i & (1<<j)) temp.push_back(v[j]);
        }
        ans.push_back(temp);
    }

    for(auto it: ans){
        cout<<"["<<" ";
        for(auto it2: it) cout<<it2<<" ";
        cout<<"]"<<endl;
    }

    return ans;
}

int main(){
    vector<int>v = {3, 8, 1};

    powerset(v);
}