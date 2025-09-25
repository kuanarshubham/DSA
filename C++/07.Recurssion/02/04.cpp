// check if any subsequnece wiith sum k is presnt

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void recc(int i, int maxLenght, int &sum, int k, vector<int>&v, bool &present){
    if(sum > k) return;
    
    if(sum == k){
        present = true;
        return;
    }

    if(i>=maxLenght){
        return;
    }

    if(present) return;

    sum+=v[i];
    recc(i+1, maxLenght, sum, k, v, present);

    if(present) return;

    sum-=v[i];
    recc(i+1, maxLenght, sum, k, v, present);
}

int getNumber(vector<int>&v, int k){
    vector<vector<int>>ans;
    vector<int> temp;

    int sum = 0;
    bool present = false;

    recc(0, v.size(), sum, k, v, present);

    cout<<present<<endl;

    return present;
}

int main(){
    vector<int>v = {4, 9, 2, 5, 1};

    int k = 10;

    getNumber(v, k);
}