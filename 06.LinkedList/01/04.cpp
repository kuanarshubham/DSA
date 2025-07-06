// serach in LL

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

int serachLL(Node*head, int x){
    int count=1;

    Node *temp=head;

    while(temp->value!=x){
        temp=temp->nxt;
        count++;
    }

    return count;
}

int main(){
    Node *head = new Node(1);
    head->nxt = new Node(2);
    head->nxt->nxt = new Node(3);
    head->nxt->nxt->nxt = new Node(4);

    cout<<serachLL(head, 1)<<" "<<serachLL(head, 3);
}