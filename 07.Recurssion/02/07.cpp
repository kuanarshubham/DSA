// subset sum - 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int k, int sum, vector<int>&v, vector<int>&ans){
    if(i>=k){
        ans.push_back(sum);
        return;
    }

    sum+=v[i];
    recc(i+1, k, sum, v, ans);
    sum-=v[i];
    recc(i+1, k, sum, v, ans);
}

vector<int> subSetSum1(vector<int>&v){
    vector<int>ans;
    int sum = 0;

    int i=0;

    recc(i, v.size(), sum, v, ans);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return ans;
}

int main(){
    vector<int>v = {5, 2, 1};

    subSetSum1(v);
}