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

Node *helper(Node* parent){
    if(parent->left==NULL) return parent->left;
    else if(parent->right==NULL) return parent->right;

    Node *temp=parent->left;
    
    while(temp->right!=NULL){
        temp=temp->right;
    }

    temp=parent->right;
    return parent->left;
}

Node *optimal(Node* root, int val){
    if(root==NULL || root->value==val) return NULL;

    Node *temp = root;

    while(root!=NULL){
        if(root->value>val){
            if(root->left!=NULL && root->left->value==val){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->value==val){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }

    return temp;
}