// segregate odd and even

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


Node *seggregate(Node*head){
    Node*even=head, *odd=head, *it=head, *evenHeader=head, *oddHeader=head;

    while(even->value%2!=0){
        even=even->nxt;
        evenHeader=evenHeader->nxt;
    }

    while(odd->value%2==0){
        odd=odd->nxt;
        oddHeader=oddHeader->nxt;
    }

    while(it!=NULL){
        if(it->value%2!=0 && it!=odd){
            odd->nxt=it;
            odd=it;
        }
        else if(it->value%2==0 && it!=even){
            even->nxt=it;
            even=it;
        }

        it=it->nxt;
    }

    if(odd==head && odd->value%2==0) return evenHeader;
    else if(even==head && even->value%2!=0) return oddHeader;
    
    odd->nxt=evenHeader;

    return oddHeader;
}