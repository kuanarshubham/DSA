// construct a bst

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

Node* insert(Node* root, int n){
    if(root==NULL) return new Node(n);

    if(root->value>n) root->left = insert(root->left, n);
    else root->right = insert(root->right, n);
}

void inorder(Node *root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->value;
    inorder(root->right);
}

Node *brute(vector<int>&nums){
    Node *root = NULL;

    for(auto it: nums){
        root = insert(root, it);
    }

    return root;
}

Node *builder(vector<int>&nums, int low, int high){
    if(low>high) return NULL;

    int mid=(low+high)/2;

    Node *root = new Node(nums[mid]);

    root->left = builder(nums, low, mid-1);
    root->right = builder(nums, mid+1, high);

    return root;
}

Node *better(vector<int>&nums){
    Node *root = NULL;

    sort(nums.begin(), nums.end());
    return builder(nums, 0, nums.size()-1);
}

Node *optimalBuild(vector<int>&nums, int i, int ub, int n){
    if(i==n || nums[i]>ub) return NULL;

    Node * root = new Node(nums[i++]);
    cout<<root->value<<" ";
    root->left = optimalBuild(nums, i, root->value, n);
    cout<<root->value<<": Part 2"<<endl;
    root->right = optimalBuild(nums, i, ub, n);

    return root;
}

Node *optimal(vector<int>&nums){
    int n=nums.size();
    return optimalBuild(nums, 0, INT_MAX, n);
}

int main(){
    vector<int>nums = {8, 5, 1, 7, 10, 12};

    optimal(nums);
}