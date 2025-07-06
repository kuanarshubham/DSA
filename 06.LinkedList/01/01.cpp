// insert a node into LL

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

void insertLL(Node *head, int val, int place){
    int count=1;
    Node *temp = head;

    while(count<place){
        temp=temp->nxt;
        count++;
    }

    Node *newNode = new Node(val);
    newNode->nxt  = temp->nxt;
    temp->nxt = newNode;
}


int main(){
    Node *head = new Node(1);
    head->nxt = new Node(2);
    head->nxt->nxt = new Node(3);
    head->nxt->nxt->nxt = new Node(4);

    insertLL(head, 100, 3);

    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->nxt;
    }
}