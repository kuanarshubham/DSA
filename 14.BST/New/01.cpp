// bst serach

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node*left, *right;

    Node(int x){
        this->value=x;
        this->right=NULL;
        this->left=NULL;
    }
};


Node* optimal(Node *root, int val){
    if(root==NULL) return root;

    while(root!=NULL && root->value!=val){
        root = root->value > val ? root->left : root->right;
    }

    return root;
}