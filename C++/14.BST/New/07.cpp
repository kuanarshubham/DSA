// kth smallest element

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

void inorder(Node *root, int &count, int k, int &kLargest){
    if(!root || k>=count) return;

    inorder(root->left, count, k, kLargest);

    count++;
    if(count == k){
        kLargest=root->value;
        return;
    }

    inorder(root->right, count, k, kLargest);
}

int optimal(Node *root, int k){
    if(root==NULL) return NULL;
    int count=0, kLargest = -1;

    inorder(root, count, k, kLargest);

    return kLargest;
}