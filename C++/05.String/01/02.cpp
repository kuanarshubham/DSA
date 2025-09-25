// reverse the words in a string

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string brute(string s){
    int n=s.size();
    string ans="";

    reverse(s.begin(), s.end());

    for(int i=0; i<n; i++){
        if(s[i]==' ') continue;
        
        string temp="";
        while(i<n && s[i]!=' '){
            temp.push_back(s[i]);
            i++;
        }

        reverse(temp.begin(), temp.end());
        ans += " " + temp;
    }

    return ans.substr(1);
}

int main(){
    string s= "The sky is pink    ";

    cout<<s<<endl;
    cout<<brute(s);
}