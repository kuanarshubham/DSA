// subset sum - 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int k, vector<int>&v, vector<int>&temp, vector<vector<int>>&ans){
    if(i>=k){
        ans.push_back(temp);
        return;
    }

    temp.push_back(v[i]);
    recc(i+1, k, v, temp, ans);
    temp.pop_back();
    recc(i+1, k, v, temp, ans);
}

vector<vector<int>>subSetSum2(vector<int>&v){
    vector<vector<int>>ans;
    vector<int>temp;

    recc(0, v.size(), v, temp, ans);

    set<vector<int>>s(ans.begin(), ans.end());
    vector<vector<int>>new_ans(s.begin(), s.end());

    for(auto it: new_ans){
        for(auto it2: it) cout<<it2<<" ";
        cout<<endl;
    }
    

    return new_ans;
}

int main(){
    vector<int> v = {1, 2, 2};
    
    subSetSum2(v);
}