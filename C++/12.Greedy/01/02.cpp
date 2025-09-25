// lemonade

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool allCustomer(vector<int>&customer){
    int n=customer.size(), fives=0, tens=0, twentys=0;

    for(int i=0; i<n; i++){
        if(customer[i] == 5) fives++;
        else if(customer[i] == 10){
            tens++;
            if(fives>=1) fives--;
            else return false;
        }
        else{
            if(tens>=1 && fives>=1){
                twentys++;
                fives--;
                tens--;
            }
            else if(fives>=3){
                twentys++;
                fives-=3;
            }
            else return false;
        }
    }

    return true;
}

int main(){
    vector<int>customer = {5, 10, 20};

    cout<<allCustomer(customer);
}