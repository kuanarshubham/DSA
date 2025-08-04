// 2 sum

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
    private:
    void pushLeft(Node *root){
        while(root!=NULL){
            n.push(root);
            root=root->left;
        }
    }

    void pushRight(Node *root){
        while(root!=NULL){
            b.push(root);
            root=root->right;
        }
    }

    public:
    stack<Node*>n, b;

    BSTIterator(Node *root){
        pushLeft(root);
        pushRight(root);
    }

    int next(){
        if(!n.empty()){
            Node *node = n.top();
            n.pop();

            if(node->right!=NULL){
                Node *temp=node;
                pushLeft(temp->right);
            }

            return node->value;
        }
        else return 0;
    }

    int before(){
        if(b.empty()) return 0;

        Node *node = b.top();
        b.pop();

        if(node->left){
            Node *temp = node;
            pushRight(temp->left);
        }

        return node->value;
    }

    bool hasNext(){
        return !n.empty();
    }
    
    bool hasBefore(){
        return !b.empty();
    }
};

pair<int, int> optimal(Node* root, int sum){
    if(root==NULL) return {NULL, NULL};

    BSTIterator bst(root);

    int i=bst.next(), j=bst.before();

    while(i<j){
        if(i+j==sum) return {i, j};
        else if(i+j<sum) i=bst.next();
        else j=bst.before();
    }

    return {-1, -1};
}