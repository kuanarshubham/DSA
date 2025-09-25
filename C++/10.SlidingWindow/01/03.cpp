//  a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute
// generate the sum multiple time
int maxScorBrute(vector<int>&cardScore, int k){
    int n = cardScore.size(), maxSum=0;
    int l = k-1, r = n;

    while(l>=0){
        int sum = 0;

        // left 0 -> l
        for(int i=0; i<=l; i++) sum += cardScore[i];
        
        // right r -> n-1
        for(int i=r; i<=n-1; i++) sum += cardScore[i];

        maxSum = max(maxSum, sum);
        l--;
        r--;
    }

    return maxSum;
}

// optimal
int maxScoreOptimal(vector<int>cardScore, int k){
    int n = cardScore.size(), maxSum=0, sumLeft =0, sumRight = 0;
    int l = k-1, r = n;

    for(int i=0; i<=l; i++) sumLeft += cardScore[i];

    maxSum = max(maxSum, sumLeft+sumRight);

    while(l>=0){
        sumLeft -= cardScore[l];
        l--;
        r--;
        sumRight += cardScore[r];

        maxSum = max(maxSum, sumLeft+sumRight);
    }

    return maxSum;
}

int main(){
    vector<int> cardScore = {5, 4, 1, 8, 7, 1, 3};
    int maxCards = 3;

    cout<<"Brute: "<<maxScorBrute(cardScore, maxCards)<<" "<<"Optimal: "<<maxScoreOptimal(cardScore, maxCards);
}