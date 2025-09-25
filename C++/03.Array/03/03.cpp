// 3 sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>brute(vector<int>&nums, int target){
    int n=nums.size();
    set<vector<int>>ans;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int sum=nums[i]+nums[j]+nums[k];

                if(sum==target){
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
            }
        }
    }

    vector<vector<int>>og_ans(ans.begin(), ans.end());

    return og_ans;
}

vector<vector<int>>better(vector<int>&nums, int target){
    int  n=nums.size();
    vector<vector<int>>ans;
    set<vector<int>>map;
    for(int i=0; i<n; i++){
        set<int>st;
        for(int j=i+1; j<n; j++){
            int thirdElemnet = target-(nums[i]+nums[j]);

            if(st.find(thirdElemnet)!=st.end()){
                vector<int>temp={nums[i], thirdElemnet, nums[j]};
                sort(temp.begin(), temp.end());
                map.insert(temp);
            }

            st.insert(nums[j]);
        }
    }

    return ans;
}

vector<vector<int>>optimal(vector<int>&nums, int target){
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        int j=i+1, k=n-1;

        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];

            if(target==sum){
                vector<int>temp={nums[i], nums[j], nums[k]};
                ans.push_back(temp);

                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if(target>sum) j++;
            else k++;
        }
    }

    return ans;
}

int main(){}