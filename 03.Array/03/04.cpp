// 4sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>brute(vector<int>&nums, int target){
    int n=nums.size();
    set<vector<int>>st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];

                    if(sum==target){
                        vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>>ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>>better(vector<int>&nums, int target){
    int n=nums.size();

    set<vector<int>>st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int>hashmap;
            for(int k=j+1; k<n; k++){
                int fourthValue = target - (nums[i] + nums[j] + nums[k]);
                
                if(hashmap.find(fourthValue)!=hashmap.end()){
                    vector<int>temp={nums[i],nums[j],nums[k],fourthValue};

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashmap.insert(nums[k]);
            }
        }
    }

    vector<vector<int>>ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>>optimal(vector<int>&nums, int target){
    int n=nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>>ans;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int k=j+1, l=n-1;
            
            while(l>k){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
               
                if(sum==target){
                    vector<int>temp={nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);

                    l--;
                    k++;
                    while(nums[k-1]!=nums[k]) k++;
                    while(nums[l+1]!=nums[l]) l--;
                }
                else if(target>sum) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main(){}