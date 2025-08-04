// validate a BST

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

bool recc(Node*root, int maxi, int mini){
    if(root==NULL) return true;

    bool l=false, r=false, m=false;
    if(root->left) l=recc(root->left, root->value, mini);

    if(root->right) r=recc(root->right, maxi, root->value);

    if(root->value>mini && root->value<maxi) m=true;

    return l & r & m;
}

bool optimal(Node *root){
    if(root==NULL) return true;

    int maxi=INT_MAX, mini=INT_MIN;

    return recc(root, maxi, mini);
}