// lenght of loop

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

int lenghtOfLoop(Node*head){
    Node*slow=head, *fast=head;

    while(fast->nxt!=NULL && fast->nxt->nxt!=NULL){
        fast=fast->nxt->nxt;
        slow=slow->nxt;

        if(fast==slow){
            int count=1;
            fast=fast->nxt;

            while(fast!=slow){
                count++;
                fast=fast->nxt;
            }

            return count+1;
        }
    }

    return 0;
}

int main(){

}