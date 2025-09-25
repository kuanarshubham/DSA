// letter combination - phone version

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// i - string
// j - phone

void recc(string s, int i, string &temp, vector<string>&phone, vector<string>&ans){
    if(i>=s.length()){
        ans.push_back(temp);
        return;
    }

    int value = s[i] - '0';
    string phoneString = phone[value];

    for(int j=0; j<phoneString.length(); j++){
        temp.push_back(phoneString[j]);
        recc(s, i+1, temp, phone, ans);
        temp.pop_back();
    }
}


vector<string>possibleStrings(string s){
    vector<string> ans;
    string temp;
    
    vector<string> phone = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    recc(s, 0, temp, phone, ans);

    for(auto it: ans){
        cout<<it<<" ";
    }

    return ans;
}



int main(){
    string s = "23";

    possibleStrings(s);
}