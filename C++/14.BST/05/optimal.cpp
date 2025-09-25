//NO USE OF VECTOR TO STORE ALL THE VALUES OF TREE



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

void inorder(Node *root, int &count, int k, int &ans){
    if(root==NULL) return;

    inorder(root->left, count, k, ans);
    count++;

    if(count == k){
        ans = root->val;
        return;
    }

    inorder(root->right, count, k, ans);
}

int kthSmallestElement(Node *root, int k){
    int count =0, ans;
    inorder(root, count, k, ans);
    return ans;
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