// best time to buy stocks

#include<iostream>
#include<vector>
using namespace std;

int optimal(vector<int>price){
    int n=price.size();

    int mini=1e9, profit=0;

    for(int i=0; i<n; i++){
        mini = min(price[i], mini);
        profit = max(profit, price[i]-mini);
    }

    return profit;
}

int main(){
    vector<int>arr = {2, 4, 5, 61, 12, 3, 5};

    cout<<optimal(arr);
}