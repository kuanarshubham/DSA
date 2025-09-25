// Generate all possible binary strings

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int n, vector<vector<int>>&v, vector<int>&temp){
    if(i>n){
        v.push_back(temp);

        return;
    }
    
    temp.push_back(0);
    recc(i+1, n, v, temp);
    temp.pop_back();
    temp.push_back(1);
    recc(i+1, n, v, temp);
    temp.pop_back();
}

vector<vector<int>>allPosibleStrings(int n){
    vector<vector<int>> v;
    vector<int> temp;

    recc(1, n, v, temp);

    for(auto it: v){
        for(auto it2: it){
            cout<<it2;
        }
        cout<<endl;
    }

    return v;
}

int main(){
    int n = 3;

    allPosibleStrings(n);
}