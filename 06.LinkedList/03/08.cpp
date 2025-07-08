// delete the middle ellement

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node*nxt;
    
    Node(int value){
        this->value=value;
        this->nxt=NULL;
    }
};

Node* deleteMid(Node* head){
    if(!head || !head->nxt) return NULL;

    Node *slow=head, *fast=head, *prev=NULL;

    while(fast->nxt!=NULL && fast->nxt->nxt!=NULL){
        fast=fast->nxt->nxt;
        prev=slow;
        slow=slow->nxt;
    }

    if(prev) prev->nxt=slow->nxt;
    else head=head->nxt;
    
    delete slow;

    return head;
}