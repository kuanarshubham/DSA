// revesre a LL using recc

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    Node(int d){
        data=d;
        next=NULL;
    }

    Node(int d, Node *n){
        data=d;
        next=n;
    }
};

Node *reverse(Node *node, Node *prev){
    if(!node) return prev;

    Node *n = reverse(node->next, prev);

    node->next=n;
    return node;
}

void print_node(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    cout<<endl;
}

int main(){
    Node *n1 = new Node(1, new Node(2, new Node(3, new Node(4))));

    Node *rev_n1 = reverse(n1, NULL);

    print_node(rev_n1);
}