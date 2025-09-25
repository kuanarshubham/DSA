// delete a node in LL

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

void deleteLL(Node*head, int place){
    int count=1;
    Node *temp = head;

    while(count<place-1){
        temp=temp->nxt;
        count++;
    }

    temp->nxt=temp->nxt->nxt;
}

int main(){
    Node *head = new Node(1);
    head->nxt = new Node(2);
    head->nxt->nxt = new Node(3);
    head->nxt->nxt->nxt = new Node(4);

    deleteLL(head, 3);

    Node *temp = head;

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->nxt;
    }
}