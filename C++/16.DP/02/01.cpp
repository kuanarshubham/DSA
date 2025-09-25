// ninja train

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(int day, int last, vector<vector<int>>&matrix, vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;

        for(int i=0; i<=2; i++){
            if(i!=last){
                maxi = max(maxi, matrix[0][i]);
            }
        }

        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;

    for(int i=0; i<=2; i++){
        int points=0;

        if(i!=last){
            points = matrix[day][i] + recc(day-1, i, matrix, dp);
        }

        maxi = max(maxi, points);
    }

    return dp[day][last] = maxi;    
}

int maxPointsMemo(vector<vector<int>>&matrix){
    vector<vector<int>>dp(matrix.size(), vector<int>(4, -1));

    return recc(matrix.size()-1, 3, matrix, dp);
}

int maxPointTab(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<vector<int>>dp(n, vector<int>(4, 0));

    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][1], matrix[0][0]);
    dp[0][3] = max(matrix[0][1], max(matrix[0][2], matrix[0][0]));

    for(int day =1; day<n; day++){
        for(int last = 0; last<4; last++){
            int maxi = 1e-8;
            for(int task =0; task<3; task++){
                if(last != task){
                    int points = matrix[day][task] + dp[day-1][task];
                    maxi = max(maxi, points);
                }
            }

            dp[day][last] = maxi;
        }
    }

    cout<<dp[n-1][3] <<" "<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<endl;
    return dp[n-1][3];
}


int spaceOptimization(vector<vector<int>>&matrix){
    int n=matrix.size();

    vector<int>prev(4, 0);

    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][1], matrix[0][0]);
    prev[3] = max(matrix[0][1], max(matrix[0][2], matrix[0][0]));


    for(int day=1; day<n; day++){
        vector<int>temp(4, 0);
        for(int last=0; last<4; last++){
            for(int task = 0; task<3; task++){
                if(last != task){
                    int point = matrix[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }

        prev = temp;
    }

    
    cout<<prev[3]<<endl;
    return prev[3];
}

int main(){
    vector<vector<int>>matrix = {
        {10, 50, 1},
        {5, 100, 11},
        {7, 11, 101}
    };

    cout<<maxPointsMemo(matrix)<<endl<<maxPointTab(matrix)<<spaceOptimization(matrix)<<endl;
}