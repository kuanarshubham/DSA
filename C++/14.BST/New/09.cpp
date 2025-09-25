// LCA

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

Node *optimal(Node *root, int x1, int x2){
    if(root==NULL) return NULL;

    int val = root->value;

    if(val<x1 && val<x2) return optimal(root->right, x1, x2);
    else if(val>x1 && val>x2) return optimal(root->left, x1, x2);
    return root;
}