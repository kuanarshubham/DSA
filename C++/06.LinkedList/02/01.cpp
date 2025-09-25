// reverse a DLL

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node*nxt;
        Node*prev;

    Node(int val){
        this->value = val;
        this->nxt = NULL;
        this->prev = NULL;
    }
};


Node *reverseLL(Node*head){
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->nxt;
        current->nxt = temp;

        // Move to next node in original order (which is prev now)
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}


int main(){
    Node *head = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    head->nxt=node2;
    node2->nxt=node3;
    node3->nxt=node4;
    node4->prev=node3;
    node3->prev=node2;
    node2->prev=head;

    Node *rev = reverseLL(head);

    Node *temp = rev;

    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=temp->nxt;
    }

}