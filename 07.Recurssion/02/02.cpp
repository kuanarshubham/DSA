// power set of set

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void recc(int i, int maxLenght, string &temp, vector<string>&v, vector<string>&ans){
    if(i>=maxLenght){
        ans.push_back(temp);
        return;
    }

    temp+=v[i][0];
    recc(i+1, maxLenght, temp, v, ans);
    temp.pop_back();
    recc(i+1, maxLenght, temp, v, ans);
}

vector<string>generateAllPossibleSets(vector<string>&v){
    string temp = "";
    vector<string>ans;
    
    recc(0, v.size(), temp, v, ans);

    int i=0;

    for(auto it: ans){
        cout<<i<<" : "<<it<<endl;
        i++;
    }

    cout<<ans.size();

    return ans;
}

int main(){
    vector<string> v = {"1", "2", "3", "4"};

    generateAllPossibleSets(v);
}