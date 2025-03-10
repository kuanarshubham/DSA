#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};


int ceilVal(Node *root, int key){
    
    int ceil = -1;

    while(root){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }
        else if(key < root->val){
            ceil = root->val;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    return ceil;
}

int main(){
    Node *n0 = new Node(10);
    Node *n1 = new Node(5);
    Node *n2 = new Node(13);
    Node *n3 = new Node(3);
    Node *n4 = new Node(6);
    Node *n5 = new Node(11);
    Node *n6 = new Node(14);
    Node *n7 = new Node(2);
    Node *n8 = new Node(4);
    Node *n9 = new Node(9);

    n0->left = n1;
    n0->right = n2;

    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    n3->left = n7;
    n3->right = n8;
    n4->right = n9;

    cout<<ceilVal(n0, 8);
}

