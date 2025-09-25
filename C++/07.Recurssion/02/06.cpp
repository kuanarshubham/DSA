// comibinational sum - 2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int k, int sum, const vector<int>&v, vector<int>&temp, vector<vector<int>>&ans){
    if(sum>k || i>=v.size()) return;

    if(sum == k){
        sort(temp.begin(), temp.end());
        ans.push_back(temp);
        return;
    }

    sum+=v[i];
    temp.push_back(v[i]);
    recc(i+1, k, sum, v, temp, ans);
    sum-=v[i];
    temp.pop_back();
    recc(i+1, k, sum, v, temp, ans);
}

vector<vector<int>> allCombinatons(vector<int>&v, int k){
    vector<int> temp;
    vector<vector<int>>ans;

    int i=0;
    int sum =0;

    recc(i, k, sum, v, temp, ans);

    sort(ans.begin(), ans.end());

    for(auto it: ans){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }

    return ans;
}

int main(){
    vector<int>v = {2, 1, 2, 7, 6, 1, 5};
    int k = 8;

    allCombinatons(v, k);
}