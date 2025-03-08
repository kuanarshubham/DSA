#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* recc(Node* root, int key){
    if(root == NULL) return NULL;
    if(root->val == key) return root;
    cout<<"Value is - "<<root->val<<endl;

    if(root->val < key) return recc(root->right, key);
    else return recc(root->left, key);
}


Node* returnNode(Node *root, int key){
    if(root == NULL) return root;

    return recc(root, key);
}

int main(){
    Node *n0 = new Node(6);
    Node *n1 = new Node(4);
    Node *n2 = new Node(8);
    Node *n3 = new Node(3);
    Node *n4 = new Node(5);
    Node *n5 = new Node(7);
    Node *n6 = new Node(9);

    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    Node *ans = returnNode(n0, 10);

    if(ans == NULL) cout<<"Not Found";
    else{
        cout<<"Answer = "<<ans->val;
    }
}
