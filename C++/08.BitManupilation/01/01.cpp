// decimal to binary
// binary to decimal

// one's complement
// two's complement

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decToBin(int x){
    string s = "";
    
    while(x){
        if(x%2==1) s+='1';
        else s+='0';

        x/=2;
    }

    reverse(s.begin(), s.end());
    return s;
}

int binToDec(string s){
    int sum = 0;

    for(int i=s.size()-1; i>=0; i--){
        if(s[i] == 0) continue;
        else{
            sum += pow(2, i);
        }
    }

    return sum;
}

int onesComplement(int x){
    return ~x;
}

int twosComplement(int x){
    return (~x)+1;
}


int main(){
    int x = 11;
    cout<<decToBin(x)<<endl;

    string s = "1111";
    cout<<binToDec(s);
}