// merge ovveralpping inetrvals

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>>mergeOverlappingIntervals(vector<pair<int,int>>&intervals){
    int n=intervals.size();

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>>ans;

    for(int i=0; i<n; i++){
        int start=intervals[i].first, end=intervals[i].second;

        if(!ans.empty() && end<=ans.back().second){
            continue;
        }

        for(int j=i+1; j<n; j++){
            if(intervals[j].first<=end){
                end =max(end, intervals[j].second);
            }
            else break;
        }

        ans.push_back({start, end});
    }

    return ans;
}


// TC = O(2N)
// SC = O(N) 
vector<pair<int, int>>brute(vector<pair<int, int>>&nums){
    int n=nums.size();

    sort(nums.begin(), nums.end());

    vector<pair<int, int>>ans;

    for(int i=0; i<n; i++){
        int start=nums[i].first, end=nums[i].second;

        if(!ans.empty() && ans.back().second>end) continue;

        for(int j=i+1; j<n; j++){
            if(nums[j].first<end) end=max(end, nums[j].second);
            else break;
        }

        ans.push_back({start, end});
    }

    return ans;
}


vector<pair<int, int>>optimal(vector<pair<int, int>>&nums){
    int n=nums.size();

    vector<pair<int, int>>ans;

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        int curr_start=nums[i].first, curr_end=nums[i].second;

        if(ans.empty() || ans.back().second<curr_start){
            ans.push_back({curr_start, curr_end});
            continue;
        }

        if(!ans.empty() && ans.back().second>curr_end) continue;
        
        if(!ans.empty() && ans.back().second>curr_start){
            int last_value_pushed_to_array_start=ans.back().first, last_value_pushed_to_array_end=ans.back().second;

            ans.pop_back();

            last_value_pushed_to_array_end = max(last_value_pushed_to_array_end, curr_end);

            ans.push_back({last_value_pushed_to_array_start, last_value_pushed_to_array_end});
        }
    }

    return ans;
}

int main(){}