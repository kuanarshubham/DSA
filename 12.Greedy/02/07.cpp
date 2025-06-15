// jump 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool possibleOrNot(vector<int>&jump){
    int n=jump.size(), maxJump=0;

    for(int i=0; i<n; i++){
        if(i > maxJump)  return false;
        maxJump = max(maxJump, i+jump[i]);
    }


    return true;
}

int main(){
    vector<int>jump = { 3, 2, 1, 0, 2, 2, 3}, jump2 = {2, 3, 4, 5, 6, 7, 8};

    cout<<possibleOrNot(jump)<<" "<<possibleOrNot(jump2);
}