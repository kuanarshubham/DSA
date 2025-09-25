// min stack

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MinStackBetter{
    stack<pair<int, int>>st;

    public:
        void minPush(int n){
            int tillNowMinVal = INT_MAX;
            
            if(st.size()>0) tillNowMinVal = this->st.top().second;
            
            if(tillNowMinVal > n){
                st.push({n, n});
            }
            else{
                this->st.push({n, tillNowMinVal});
            }
        }

        int getMin(){
            return this->st.top().second;
        }

        void minPop(){
            this->st.pop();
        }

        int minTop(){
            return this->st.top().first;
        }
};

class MinStackBest{
    stack<int>st;
    int min;

    public:
        void minPush(int n){
            if(st.empty()){
                st.push(n);
                min=n;
            }
            else{
                if(min>n){
                    st.push(2*n - min);
                    min = n;
                }
                else st.push(n);
            }
        }

        void minPop(){
            if(st.empty()) return;
            else{
                int topEncodedVal = st.top();

                if(topEncodedVal < min){
                    min = 2*min - topEncodedVal;
                }

                st.pop();
            }
        }

        int minTop(){
            if(st.empty()) return -1;
            else{
                int topVal = st.top();

                if(topVal < min){
                    return min;
                }

                return topVal;
            }
        }

        int getMin(){
            return min;
        }
};

int main(){

}