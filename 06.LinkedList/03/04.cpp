// detect a loop

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

bool detectCycle(Node*head){
    Node*slow=head, *fast=head;

    while(fast->nxt!=NULL && fast->nxt->nxt!=NULL){
        fast=fast->nxt->nxt;
        slow=slow->nxt;

        if(fast==slow) return true;
    }

    return false;
}

int main(){

}