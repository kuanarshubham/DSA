// max sum combinational

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>maxSumBrute(vector<int>&v1, vector<int>&v2, int k){
    int n=v1.size();

    priority_queue<int>pq;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            pq.push(v1[i]+v2[j]);
        }
    }

    vector<int>ans;

    while(!pq.empty()){
        if(ans.size() >= k){
            break;
        }

        ans.push_back(pq.top());
        pq.pop();
    }

    for(auto it: ans) cout<<it<<" ";

    return ans;
}

vector<int>maxSumOptimal(vector<int>&v1, vector<int>&v2, int k){
    int n=v1.size();

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int>ans;
    priority_queue<pair<int, pair<int, int>>>pq;
    set<pair<int, int>>st;

    pq.push({v1[n-1] + v2[n-1], {n-1, n-1}});
    st.insert({n-1, n-1});

    while(!pq.empty() && k--){
        int sum = pq.top().first;
        pair<int, int> idx = pq.top().second;
        pq.pop();

        ans.push_back(sum);

        int x=idx.first, y=idx.second;
        
        if(x-1 >=0 && st.count({x-1, y}) == 0){
            pq.push({v1[x-1] + v2[y], {x-1, y}});
            st.insert({x-1, y});
        }

        if(y-1>=0 && st.count({x, y-1}) == 0){
            pq.push({v1[x]+v2[y-1], {x, y-1}});
            st.insert({x, y-1});
        }
    }

    for(auto it: ans) cout<<it<<" ";

    return ans;
}

int main(){
    vector<int>arr1 = {10, 3, 1}, arr2 = {4, 2, 1};

    maxSumBrute(arr1, arr2, 3);
    maxSumOptimal(arr1, arr2, 3);
}