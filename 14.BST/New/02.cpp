// min/max in a bst

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

pair<int, int>optimal(Node* root, int val){
    if(root==NULL) return {-1, -1};

    int mini, maxi;

    Node *temp = root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    mini = temp->value;

    temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    maxi = temp->value;

    return {mini, maxi};
}