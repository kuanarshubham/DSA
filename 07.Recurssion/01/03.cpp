// sort a stack using recurssion

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortInsert(stack<int>&s, int x){
    if(s.empty() || x > s.top()){
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    sortInsert(s, x);
    s.push(temp);
}

void sortT(stack<int>&s){
    if(!s.empty()){
        int x = s.top();
        s.pop();
        sortT(s);
        sortInsert(s, x);
    }
}

int main(){
    stack<int>s;

    s.push(10);
    s.push(77);
    s.push(6);
    s.push(7);
    s.push(99);

    sortT(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
}