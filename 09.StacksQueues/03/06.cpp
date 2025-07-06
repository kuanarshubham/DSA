// astroid collison

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int asteriod(vector<int>&arr){
    int n=arr.size();
    stack<int>st;

    for(int i=0; i<n; i++){
        if(arr[i]>0){
            st.push(arr[i]);
        }
        else if(arr[i]<0){
            int negAstroid = abs(arr[i]);
            
            while(!st.empty() && negAstroid>st.top()) st.pop();

            if(!st.empty() && negAstroid==st.top()) st.pop();
        }
        else continue;
    }

    return st.empty() ? -1 : 1;
}

int main(){

}