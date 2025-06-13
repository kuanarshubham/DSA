// insert interval

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>insertInto(vector<pair<int, int>>&v, pair<int, int>x){
    int n=v.size();
    vector<pair<int, int>>ans;

    int i=0;

    while(i<n && v[i].second < x.first){
        ans.push_back(v[i]);
        i++;
    }

    while(i<n && x.second>v[i].first){
        x.first = min(x.first, v[i].first);
        x.second = min(x.second, v[i].second);
        i++;
    }

    ans.push_back({x.first, x.second});
    i++;

    while(i<n){
        ans.push_back(v[i]);
        i++;
    }

    for(auto it: ans) cout<<it.first<<" "<<it.second<<endl;

    return ans;
}

int main(){
    vector<pair<int, int>>v = {{1, 2}, {3, 4}, {5, 7}, {8, 10}, {12, 16}};
    pair<int, int>x =  {6, 8};

    insertInto(v, x);
}