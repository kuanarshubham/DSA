#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left, *right;

    Node(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* addNode(Node *root, int x){
    Node *newNode = new Node(x);
    if(root == NULL) return newNode;
    
    Node *temp = root;

    while(true){
        if(x > temp->val){
            if(temp->right!=NULL) temp = temp->right;
            else{
                temp->right = newNode;
                break;
            }
        }
        else if(x < temp->val){
            if(temp->left != NULL) temp = temp->left;
            else{
                temp->left = newNode;
                break;
            }
        }
    }

    return root;
}

int main(){
    Node *head = new Node(4);
    Node *n1 = new Node(2);
    Node *n2 = new Node(7);
    Node *n3 = new Node(1);
    Node *n4 = new Node(3);

    head->left = n1;
    head->right = n2;
    n1->left = n3;
    n1->left = n4;

    addNode(head, 5);
}