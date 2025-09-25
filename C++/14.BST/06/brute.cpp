#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left, *right;

    Node(int x): val(x), left(NULL), right(NULL) {}
};

void recc(Node *root, int max, int min, bool &b){
    if(!b) return;
    if(root == NULL) return;
    cout<<"Root value: "<<root->val<<" ["<<min<<", "<<max<<"] "<<endl;

    if(max < root->val || min > root->val){
        cout<<"Inside if"<<endl;
        b = false;
    } 

    recc(root->left, root->val, min, b);
    recc(root->right, max, root->val, b);
}

bool isTreeBst(Node *root){
    int max = INT_MAX;
    int min = INT_MIN;
    
    bool b = true;
    recc(root, max, min, b);
    return b;
}


int main(){
    Node *head = new Node(5);
    Node *n1 = new Node(1);
    Node *n2 = new Node(7);
    Node *n3 = new Node(6);
    Node *n4 = new Node(8);

    head->left = n1;
    head->right = n2;

    n2->left = n3;
    n2->right = n4;

    cout<<(isTreeBst(head) == 0?  "false": "true");
}