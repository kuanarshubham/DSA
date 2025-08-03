// insert a node in BST

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
    Node *newNode = new Node(val);
    
    Node *temp = root;

    while(true){
        if(temp->value<=val){
            if(temp->right==NULL){
                temp->right = newNode;
                break;
            }
            else{
                temp = temp->right;
            }
        }
        else{
            if(temp->left==NULL){
                temp->left = newNode;
                break;
            }
            else{
                temp=temp->left;
            }
        }
    }

    return root;
}