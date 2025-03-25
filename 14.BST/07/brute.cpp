#include<iostream>
#include<bits/stdc++.h>
using  namespace std;

class Node{
    public:
    int val;
    Node *left, *right;

    Node(int x): val(x), left(NULL), right(NULL){}
};

void recc(Node *temp, int x, Node *prev){
    if(temp == NULL) return;
    cout<<"temp: "<<temp->val<<" prev: "<<prev->val<<endl;
    if(temp->val == x) return;

    recc(temp->left, x, temp);
    recc(temp->right, x, temp);
}

Node *deletetion(Node *root, int x){
    Node *temp = root;
    Node *prev = temp;
    recc(temp, x, prev);
    return temp;
}

int main(){
    Node *head = new Node(5);
    Node *n1 = new Node(3);
    Node *n2 = new Node(6);
    Node *n3 = new Node(2);
    Node *n4 = new Node(4);
    Node *n5 = new Node(7);

    head->left = n1;
    head->right = n2;
    
    n1->left = n3;
    n1->right  = n4;

    n2->right = n5;


    cout<<deletetion(head, 7)->val;
}