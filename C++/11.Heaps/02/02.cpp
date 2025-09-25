// sort k sorted array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>sortKArryBrute(vector<vector<int>>v){
    int n=v.size();
    vector<int>ans;

    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            ans.push_back(v[i][j]);
        }
    }

    sort(ans.begin(), ans.end());

    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

    return ans;

}

class comapare{
    public:
        bool operatorMethod(pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b){
            return a.first > b.first;
        }
};

// pair<int, pair<int, int>> => (data, (row, col))

vector<int>sortKArrayOptimal(vector<vector<int>>&v){
    int n=v.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>minHeap;


    // push first element of each arrry
    for(int i=0; i<n; i++) minHeap.push({v[i][0], {i, 0}});

    vector<int>ans;

    // compare the first elemnt then the elment is pushed and the same arr nxt element is pushed to the array
    while(minHeap.size() >= 1){
        int data = minHeap.top().first, row=minHeap.top().second.first, col=minHeap.top().second.second;
        minHeap.pop();

        ans.push_back(data);
        
        if(v[row].size() > col+1) minHeap.push({v[row][col+1], {row, col+1}});

    }

    for(auto it: ans) cout<<it<<" ";

    return ans;
}

int main(){
    vector<vector<int>> v = {{1, 4, 5}, {1, 3, 4}, {2, 6}};

    sortKArryBrute(v);
    sortKArrayOptimal(v);
}