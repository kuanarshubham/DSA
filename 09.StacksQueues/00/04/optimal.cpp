#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<int> st;
    int mini = INT_MAX;

    public:
    // void push(int x){
    //     if(st.empty()) st.push(x);
    //     else{
    //         int top =  st.top();
    //         st.push(2*x - top);
    //     }
    // }

    // void pop(){
    //     if(st.empty()) return;

    //     st.pop();
    // }

    // void top(){
    //     if(st.empty()) return;
        
    //     int top = (st.top() + mini)/2;
    //     cout<<"The top val is : "<<top<<endl;
    // }
};