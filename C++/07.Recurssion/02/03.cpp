// sum of subseq whose value is k

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int maxLenght, int &sum, int k, vector<int>&v, vector<int>&temp, vector<vector<int>>&ans){
    if(sum == k){
        ans.push_back(temp);
        return;
    }

    if(i>=maxLenght){
        return;
    }

    sum+=v[i];
    temp.push_back(v[i]);
    recc(i+1, maxLenght, sum, k, v, temp, ans);

    sum-=v[i];
    temp.pop_back();
    recc(i+1, maxLenght, sum, k, v, temp, ans);
}

vector<vector<int>>generateAllSubSeq(vector<int>&v, int k){
    vector<vector<int>>ans;
    vector<int> temp;

    int sum = 0;

    recc(0, v.size(), sum, k, v, temp, ans);

    for(auto it: ans){
        for(auto it2: it) cout<<it2<<" ";
        cout<<endl;
    }

    return ans;
}

int main(){
    vector<int>v = {4, 9, 2, 5, 1};

    int k = 10;

    generateAllSubSeq(v, k);
}