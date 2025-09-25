// find a range so that min 1 elemnt of from each arry is in the range
// each array has same size
// aranged in ascending order

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int>rangeBrute(vector<vector<int>>&v){
    int n=v.size(), m=v[0].size();

    int maxi=INT_MIN, mini=INT_MAX;

    int start, end, diff=INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<m; j++){
            
        }
    }

    cout<<mini<<", "<<maxi<<endl;

    return {mini, maxi};
}



class node{
    public:
        int data, row, col;

        node(int data, int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(node*a, node*b){
            return a->data > b->data;
        }
};

pair<int, int>rangeOptimal(vector<vector<int>>&v){
    int n=v.size(), m=v[0].size(), maxi=INT_MIN, mini=INT_MAX;

    priority_queue<node*, vector<node*>, compare>minHeap;

    for(int i=0; i<n; i++){
        maxi = max(maxi, v[i][0]);
        mini = min(mini, v[i][0]);

        minHeap.push(new node(v[i][0], i, 0));
    }

    int start=mini, end=maxi;

    while(!minHeap.empty()){
        int data=minHeap.top()->data,  row=minHeap.top()->row, col=minHeap.top()->col;

        minHeap.pop();

        mini = data;

        if((maxi - mini) < (end - start)){
            start = mini;
            end = maxi;
        }

        if(col+1 < m){
            maxi = max(maxi, v[row][col+1]);
            minHeap.push(new node(v[row][col+1], row, col+1));
        }
        else break;

    }

    cout<<start<<" "<<end<<endl;

    return {start, end};
}

int main(){
    vector<vector<int>>v = {{1, 10, 11,}, {2, 3, 20}, {5, 6, 20}};

    rangeBrute(v);

    rangeOptimal(v);
}