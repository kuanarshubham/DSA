// floor of a value

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


int optimal(Node*root, int val){
    if(root==NULL) return NULL;

    Node*temp = root;

    int floor=1e9;
    while(temp!=NULL){
        if(temp->value == val) return temp->value;
        else if(temp->value>val){
            temp = temp->left;
        } 
        else{
            floor=temp->value;
            temp = temp->right;
        }
    }

    return floor;
}