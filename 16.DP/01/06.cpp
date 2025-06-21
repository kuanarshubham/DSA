// house robber - hosues in circular order

// just take 2 arrays with on 1st arry with 0th element and 2nd array with last element

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(vector<int>&money, int currHouse){
    if(currHouse == 0) return money[0];

    if(currHouse<0) return 0;

    int takeTheHouse = money[currHouse] + recc(money, currHouse-2);
    int doNotTakeTheHouse = recc(money, currHouse-1);

    return max(takeTheHouse, doNotTakeTheHouse);
}

int maxMoneyCircularHouse(vector<int>&money){
    int n=money.size();
    vector<int>temp1, temp2;

    for(int i=0; i<n; i++){
        if(i!=n-1) temp1.push_back(money[i]);
        if(i!=0) temp2.push_back(money[i]);
    }

    return max(recc(money, temp1.size()-1), recc(money, temp2.size()-1));
}

int main(){
    vector<int>money = {7, 1, 3, 2, 1, 6};
    cout<<maxMoneyCircularHouse(money);
}