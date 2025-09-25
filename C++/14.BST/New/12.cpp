// BSTIterator

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

class BSTIterator{
    public:
    stack<Node*>st;

    BSTIterator(Node *root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }

    Node *next(){
        Node* node = st.top();
        st.pop();

        if(node->right){
            Node *temp = node;
            temp=temp->right;
            while(temp!=NULL){
                temp=temp->left;
                st.push(temp);
            }
        }

        return node;
    }

    bool hasNext(){
        return !st.empty();
    }
};