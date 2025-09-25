// combnination 3

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int val, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
    if (temp.size() == n && k == 0) {
        ans.push_back(temp);
        return;
    }

    if (temp.size() > n || val > 9 || k < 0) return;

    // Include val
    temp.push_back(val);
    recc(val + 1, n, k - val, temp, ans);
    temp.pop_back();

    // Exclude val
    recc(val + 1, n, k, temp, ans);
}

vector<vector<int>>combin3(int n, int k){
    vector<vector<int>>ans;
    vector<int>temp;

    int i=1, currSum = 0, val = 1;

    recc(val, n, k, temp, ans);

    for(auto it: ans){
        for(auto it2: it) cout<<it2<<" ";
        cout<<endl;
    }

    return ans;
}

int main(){
    int n = 3;
    int k = 9;

    combin3(n, k);
}