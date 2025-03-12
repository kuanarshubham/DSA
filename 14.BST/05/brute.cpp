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

void inorder(Node *root, vector<int> &v){
    if(root==NULL) return;

    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

int kthSmallestElement(Node *root, int k){
    vector<int> v;
    inorder(root, v);
    return v[k-1];
}

int main(){
    Node *head = new Node(5);
    Node *n1 = new Node(2);
    Node *n2 = new Node(8);
    //Node *n3 = new Node(2);
    Node *n4 = new Node(4);

    head->left = n1;
    head->right = n2;
    //n1->left = n3;
    n1->right = n4;

    cout<<kthSmallestElement(head, 2);

}