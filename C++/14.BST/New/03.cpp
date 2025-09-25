// ceil in bst

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

int optimal(Node *root, int val){
    if(root==NULL) return NULL;
    
    Node* temp = root;

    int ceil=-1;

    while(temp!=NULL){
        if(root->value==val) return temp->value;
        else if(val>temp->value) temp = temp->right;
        else{
            ceil=temp->value;
            temp=temp->left;
        }
    }

    return ceil;
}