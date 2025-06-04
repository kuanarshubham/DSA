// Fruits in a basket

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fruitInBasketBrute(vector<int>&v, int fruits){
   int n = v.size(), maxLen = 0, fruitArr[fruits] = {0};
   
   for(int i=0; i<n; i++){
    set<int>s;
    for(int j=i; j<n; j++){
        s.insert(v[j]);
        if(s.size()>fruits) break;

        maxLen = max(maxLen, j-i+1);
    }
   }
   return maxLen;
}

int fruitInBasketBetter(vector<int>&v, int fruits){
    int n = v.size(), l = 0, r = 0, maxLen = 0;

    map<int, int>mpp;
    while(r<n){
        mpp[v[r]]++;

        if(mpp.size()>fruits){
            int x = v[l];
            while(mpp[x]!=0){
                mpp[v[l]]--;
                l++;
            }

            mpp.erase(x);
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}


int fruitInBasketOptimal(vector<int>&v, int fruits){
    int n = v.size(), l = 0, r = 0, maxLen = 0;

    map<int, int>mpp;
    while(r<n){
        mpp[v[r]]++;

        if(mpp.size()>fruits){
            while(mpp.size() > fruits){
                mpp[v[l]]--;

                if(mpp[v[l]] == 0){
                    mpp.erase(v[l]);
                }

                l++;
            }
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }

    return maxLen;
}


int main(){
    vector<int>v = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout<<fruitInBasketBrute(v, 2)<<" "<<fruitInBasketBetter(v, 2)<<" "<<fruitInBasketOptimal(v, 2);
}