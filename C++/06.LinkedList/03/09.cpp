// sort 0, 1, 2 in LL

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

Node *sort012LL(Node*head){
    if(head==NULL || head->nxt==NULL) return head;

    Node*zeros=new Node(-1), *ones=new Node(-1), *twos=new Node(-1);
    Node*zerosDummy=zeros, *onesDummy=ones, *twosDummy=twos;

    Node *temp=head;

    while(temp!=NULL){
        if(temp->value==0){
            zeros->nxt=temp;
            zeros=temp;
        }
        else if(temp->value==1){
            ones->nxt=temp;
            ones=temp;
        }
        else{
            twos->nxt=temp;
            twos=temp;
        }

        temp=temp->nxt;
    }

    zeros->nxt=onesDummy->nxt;
    ones->nxt=twosDummy->nxt;
    twos->nxt=NULL;

    return zerosDummy->nxt;
}

int main(){
    Node *head = new Node(1);
    head->nxt = new Node(0);
    // head->nxt->nxt = new Node(0);
    // head->nxt->nxt->nxt = new Node(2);
    // head->nxt->nxt->nxt->nxt = new Node(1);

    Node *temp = sort012LL(head);

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->nxt;
    }
}