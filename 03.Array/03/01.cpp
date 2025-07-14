//  pascal traingle

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long nCrLong(int n, int r){
    long long result=1;

    for(int i=0; i<r; i++){
        result*=(n-i/(i+1));
    }

    return result;
}

int nCr(int n, int r){
    int result=1;

    for(int i=0; i<r; i++){
        result*=(n-i/(i+1));
    }

    return result;
}

long long getElement(int row, int col){
    int newRow=row-1, newCol=col-1;

    return nCrLong(newRow, newCol);
}

vector<int>getRow(int row){
    vector<int>ans;

    int newRow=row-1;
    cout<<1<<" ";
    for(int i=0; i<row; i++){
        if(i==0 || i==row-1){
            ans.push_back(1);
            continue;
        }

        int ele = (ans[i-1]*(newRow-i+1))/i;
        ans.push_back(ele);
        cout<<ele<<" ";
    }
    cout<<1<<" "<<endl;

    return ans;
}








vector<vector<int>>getTraingle(int row){
    int newRow=row-1;

    vector<vector<int>>ans;

    for(int i=1; i<=newRow; i++){
        ans.push_back(getRow(i));
    }

    return ans;
}

int main(){
    // cout<<"  ";
    // getRow(4);
    // cout<<" ";
    // getRow(5);
    // getRow(6); 
    
    getTraingle(6);
}