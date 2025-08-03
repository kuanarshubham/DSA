// delete a node in BST

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

Node *optimal(Node* root, int val){
    if(root==NULL || root->value==val) return NULL;

    Node *temp = root, *leftTemp=NULL;

    while(true){
        if(root->value==val){
            
        }
    }
}