// Number of substring containing all three characters

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int noContainingAll3CharBrute(string s){
    int count=0, n=s.size();
    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++){
        mpp.clear();
        for(int j=i; j<n; j++){
            mpp[s[j]] = 1;
            
            if(mpp['a'] == 1 && mpp['b'] == 1 && mpp['c'] == 1){
                count++;
            }
        }
    }

    return count;
}

int noContainingAll3CharBetter(string s){
    int n=s.size(), count=0;
    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++){
        mpp.clear();
        for(int j=i; j<n; j++){
            mpp[s[j]] = 1;
            
            if((mpp['a'] == 1) && (mpp['b'] == 1) && (mpp['c'] == 1)){
                count+=(n-j);
                break;
            }
        }
    }

    return count;
}

// ending with a min substring with abc/bac/cba/cab/acb/bca and then takes the substring from left
int noContainingAll3CharOptimal(string s){
    int n=s.size(), r=0, count=0;
    int arr[3] = {-1, -1, -1};

    while(r<n){
        arr[s[r] - 'a'] = r; 
        
        if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1) count += (1 + min(min(arr[0], arr[1]), arr[2]));

        r++;
    }

    return count;
}

int main(){
    string s = "bbacba";
    
    cout<<noContainingAll3CharBrute(s)<<" "<<noContainingAll3CharBetter(s)<<" "<<noContainingAll3CharOptimal(s)<<endl;
}