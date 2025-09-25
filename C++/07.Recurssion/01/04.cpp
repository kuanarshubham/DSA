// char Atoi

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int charAtio(string s){
    int low = static_cast<int>('0');
    int high = static_cast<int>('9');

    int val=0;
    int neg = 1;
    int i=0;

    while( (static_cast<int>(s[i])>low && static_cast<int>(s[i])<high) || s[i]== ' ' || s[i] == '+' || s[i] == '-'){
        if(s[i]  == ' ' || s[i] == '+'){
            i++;
            continue;
        }

        if(s[i] == '-' || i==0){
            neg = -1;
            i++;
            continue;
        }
        
        val += static_cast<int>(s[i]) - low;
        val *= 10;
        i++;
    }

    return val/10 * neg;
}

void recurr(string s, int i, int &sum, int low, int high, bool &neg){
    if (i >= s.length()) return;

    if(s[i] == ' '){
        i++;
    }
    else if(s[i] == '+') i++;
    else if(s[i] == '-' && i>0 && s[i-1] == ' '){
        neg = true;
        i++;
    }
    else if (static_cast<int>(s[i])>=low && static_cast<int>(s[i])<=high){
        sum += static_cast<int>(s[i]) - low;
        sum *= 10;
        i++;
    }

    recurr(s, i, sum, low, high, neg);
}

int charAtio2(string s){
    int low = static_cast<int>('0');
    int high = static_cast<int>('9');
    int sum = 0;
    bool neg = false;

    recurr(s, 0, sum, low, high, neg);

    return sum;
}

int main(){
    vector<string> s = {
        "42",
        " -42",
        "133c02",
        "0-1",
        "words 0 9",
        "+990"
    };

    for(auto it: s){
        cout<<charAtio2(it)<<endl;
    }

    //cout<<charAtio(s[1]);

}