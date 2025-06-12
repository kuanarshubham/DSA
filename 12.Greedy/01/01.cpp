// asign cookies

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numOfCookies(vector<int>&greed, vector<int>cookie){
    int nG = greed.size(), nC=cookie.size(), i=0, j=0, count=0;

    while(i<nG && j<nC){
        if(greed[i]<=cookie[j]){
            i++;
            count++;
        }
        j++;
    }

    return count;
}



int main(){
    vector<int>greed = {1, 2};
    vector<int>cookie = {1, 2, 3};

    cout<<numOfCookies(greed, cookie);
}