// inorder sucessors

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int value;
    Node *left, *right;

    Node(int x){
        this->value=x;
        this->left=NULL;
        this->right=NULL;
    }
};

void inorder(Node *root, vector<int>&nums){
    if(root == NULL) return;

    inorder(root->left, nums);
    nums.push_back(root->value);
    inorder(root->right, nums);
}

int brute(Node *root, int n){
    if(!root) return 0;

    vector<int>nums;

    inorder(root, nums);

    int low = 0, high=nums.size()-1, ans;

    while(low<=high){
        int mid = low + ((high-low)/2);

        if(nums[mid]==n){
            ans = mid;
            break;
        }
        else if(nums[mid]>n) high=mid-1;
        else low = mid+1;
    }

    if(ans<=nums.size()-1) return ans;
    
    return INT_MAX;
}

int optimal(Node *root, int n){
    if(!root) return 0;

    int succ = -1;

    while(root!=NULL){
        if(root->value>n){
            succ = root->value;
            root = root->left;
        }
        else{
            root=root->right;
        }
    }

    return succ;
}