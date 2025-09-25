// add 1 to number rep by LL

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

Node *reverseLL(Node*head){
    Node*curr=head, *next, *prev=NULL;

    while(curr!=NULL){
        next=curr->nxt;
        curr->nxt=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

Node *addOne(Node*head){
    if(head==NULL) return new Node(1);
    
    Node *temp = reverseLL(head), *prev=NULL, *newHead=temp;
    bool carry=true;

    while(temp!=NULL && carry){
        prev=temp;
        int sum=temp->value+1;
        carry=sum/10 > 0 ? true : false;
        temp->value=sum%10;
    }

    if(carry) prev->nxt = new Node(1);

    return  reverseLL(newHead);
}

int carryRecc(Node*head){
    if(head==NULL) return 1;
    
    int carry = carryRecc(head->nxt);
    head->value = head->value+1;

    if(head->value<10) return 0;
    else{
        head->value = head->value%10;
        return 1;
    }
}

Node *addOneOptimal(Node *head){
    if(!head) return new Node(1);

    int carry = carryRecc(head);
    if(carry){
        Node *newNode = new Node(1);
        newNode->nxt=head;
        return newNode;
    }
    
    return head;
}