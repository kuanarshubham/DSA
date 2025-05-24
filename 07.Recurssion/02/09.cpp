// letter combination - phone version

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// i - string
// j - phone

void recc(int i,, string &num, int j, string &temp, vector<string>&ans, vector<string>&phone){
    if(i>=maxI){
        ans.push_back(temp);
        return;
    }

    int x = int(num[i]) - int('0');

    string z = phone[x];

    for(int i=0; i<z.size(); i++){
        temp.push_back(z[i]);
        recc(i+1, maxI, num, j, maxJ, temp, ans, phone);

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

    
}

int main(){
    string s = "242";

    int x = 1 + (int(s[0]) - int('0'));
    cout<<x;
}