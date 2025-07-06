// reverse the LL recurssion

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

Node *recc(Node*head, Node*prev){
    if(head==NULL) return prev;

    Node* next=head->nxt;
    head->nxt=prev;

    return recc(next, head);
}

int main(){
}