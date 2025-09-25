// reverse a LL

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node*nxt;

    Node(int val){
        this->value = val;
        this->nxt = NULL;
    }
};


Node *reverseLL(Node*head){
    Node *curr=head, *prev=NULL, *next;

    while(curr!=NULL){
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

int main(){
}