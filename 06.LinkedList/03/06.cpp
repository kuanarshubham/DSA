//check if the LL is palindrome

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node*nxt;
    
        Node(int val){
            this->value=val;
            this->nxt=NULL;
        }
};

Node* reverseLL(Node*head){
    Node *curr=head, *next, *prev=NULL;

    while(curr!=NULL){
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

bool plaindrome(Node*head){
    Node*slow=head, *fast=head;
    bool odd=false;

    while(fast->nxt!=NULL && fast->nxt->nxt!=NULL){
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }

    if(fast->nxt==NULL){
        odd=true;
    }

    slow=slow->nxt;

    Node*start=head;
    Node*mid=reverseLL(slow);

    while(mid!=NULL){
        if(mid->value!=start->value) return false;

        mid=mid->nxt;
        start=start->nxt;
    }

    return true;
}