// 	Partition Equal Subset Sum

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool recc(vector<int>& arr, int i, int sum, int totalSum, vector<vector<int>>& dp) {
    if (i == 0) {
        bool take = sum + arr[i] == totalSum / 2;
        bool notTake = sum == totalSum / 2;
        return take || notTake;
    }

    if (dp[i][sum] != -1) return dp[i][sum];

    bool take = false;
    if (sum + arr[i] <= totalSum / 2)
        take = recc(arr, i - 1, sum + arr[i], totalSum, dp);

    bool notTake = recc(arr, i - 1, sum, totalSum, dp);

    return dp[i][sum] = take || notTake;
}

bool equalSets(vector<int>& arr) {
    int n = arr.size(), totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum % 2 != 0) return false;

    vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
    return recc(arr, n - 1, 0, totalSum, dp);
}

vector<int>tabs(vector<int>& arr){
    vector<vector<bool>>dp;

    
}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    cout << equalSets(arr); // Output: 0 (false)
}
