#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *prev, *next;

    Node(int x): val(x), prev(NULL), next(NULL) {}
};

class BSTItenrator{
    public:
    stack<Node*> st;

    BSTItenrator(Node* x){
        pushAll(x);
    }

    bool hasNext(){
        return !st.empty();
    }

    int nextVal(){
        Node *temp = st.top();
        st.pop();
        pushAll(temp->prev);
        return temp->val;
    }

    void pushAll(Node *root){
        for (; root != NULL; st.push(root), root = root->prev);
    }
};



int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
    Node *n10 = new Node(10);

    n7->prev = n3;
    n7->next  = n10;

    n3->prev = n2;
    n3->next = n6;

    n2->prev = n1;

    n6->prev = n5;
    n5->prev = n4;

    n10->prev = n9;
    n9->prev = n8;

    BSTItenrator bst(n3);

    cout<<bst.nextVal()<<endl;
    cout<<bst.nextVal()<<endl;
    cout<<bst.nextVal()<<endl;
    cout<<bst.nextVal()<<endl;
}