// hands of straight

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>&hands, int groupSize){
    int n=hands.size();

    if(n%groupSize!=0) return false;

    map<int, int>mpp;

    for(auto it: hands) mpp[it]++;

    while(!mpp.empty()){
        auto it = mpp.begin();
        int value = it->first;
        mpp[value]--;

        if(mpp[value] == 0) mpp.erase(value);

        for(int i=2; i<=groupSize; i++){
            value++;
            if(mpp.find(value)==mpp.end()) return false;
            mpp[value]--;

            if(mpp[value] == 0) mpp.erase(value);
        }
    }

    return true;
}

int main(){
    vector<int>hands = {1,2,3,6,2,3,4,9,10};
    cout<<possible(hands, 3);
}