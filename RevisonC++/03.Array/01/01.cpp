// intersection

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>inter(vector<int>&arr1, vector<int>&arr2){
    int n1=arr1.size(), n2=arr2.size();

    set<int>st(arr1.begin(), arr1.end());

    vector<int>ans;

    for(int i=0; i<n2; i++){
        if(st.find(arr2[i])!=st.end()){
            if(ans.size()==0 || ans.back()!=arr2[i]) ans.push_back(arr2[i]);
        }
    }

    return ans;
}

int main(){

}