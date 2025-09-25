// roman number to integer

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int toInt(string s){
    int n=s.size(), ans=0;

    map<char, int> romanToInt = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    for(int i=1; i<n; i++){
        int prev=romanToInt[s[i-1]], curr=romanToInt[s[i]];

        if(prev<curr) ans-=prev;
        else ans+=prev;
    }

    ans+=romanToInt[s[n-1]];

    return ans;
}

string toRoman(int n){
    vector<pair<int, string>> intToRoman = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}       
    };

    int i=12; 
    string ans="";

    while(i){
        int div = intToRoman[i].first;
        string value = intToRoman[i].second;
        int divisor = n/div;
        if(divisor>0){
            for(int i=1; i<=divisor; i++) ans+=value;

            n%=div;
        }
        i--;
    }

    return ans;
}

int main(){
    string s = "MCMXCIV";
    cout<<toInt(s)<<endl;
    cout<<toRoman(1994);
}