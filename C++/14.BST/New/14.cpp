// recover bst

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
    if(root==NULL) return;

    inorder(root->left, nums);
    nums.push_back(root->value);
    inorder(root->right, nums);
}

Node *brute(Node *root){
    if(root==NULL) return NULL;

    vector<int>nums;
    inorder(root, nums);

    int i, j;

    for(int )
}