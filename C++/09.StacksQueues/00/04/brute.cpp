#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<pair<int, int>>st;

    public:
    void push(int x){
        int currMini = st.empty() ? x : st.top().second;
        
        if(currMini>x) st.push({x, x});
        else st.push({x, currMini});
    }

    void pop(){
        if(st.empty()) return;

        st.pop();
    }

    void top(){
        if(st.empty()) return;
        cout<<"The top val is : "<<st.top().first<<endl;
    }

    void getMini(){
        cout<<"The min valiue is "<<st.top().second<<endl;
    }
};


int main(){
    MinStack x;
    x.push(4);
    x.push(5);
    x.getMini();
    x.push(1);
    x.getMini();
}