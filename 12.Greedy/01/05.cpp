// valid parentheseis

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool recc(string s, int i, int count){
    if(i>=s.size()) return count==0;

    if(count<0) return false;

    if(s[i] == '(') return recc(s, i+1, count+1);
    if(s[i] == ')') return recc(s, i+1, count-1);

    return  recc(s, i+1, count) || recc(s, i+1, count+1) || recc(s, i+1, count-1);
}

bool validity(string s){
    return recc(s, 0, 0);
}

bool validityOptimal(string s){
    int max=0, min=0, n=s.size();

    for(int i=0; i<n; i++){
        if(s[i] == ')'){
            min-=1;
            max-=1;
        }
        else if(s[i] == '('){
            min+=1;
            max+=1;

            if(min<0) min=0;
        }
        else if(s[i] == '*'){
            min-=1;
            max+=1;

            if(min<0) min = 0;
        }
    }

    return min==0 || max==0;
}

int main(){
    string s = "(()())";
    string s2 = "((*)(";

    cout<<validity(s)<<" "<<validity(s2)<<" "<<validityOptimal(s)<<" "<<validityOptimal(s2);
}