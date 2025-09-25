#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key, val;
    Node *nxt, *prev;

    Node(int x, int y){
        key=x, val=y;
        nxt=NULL;
        prev=NULL;
    }
};

class LRU{
    public:
    int size;
    unordered_map<int, Node*>mpp;
    Node *tail, *head;

    LRU(int val){
        size=val;
        tail->key = tail->val = head->key = head->val = -1;
        tail->prev = head;
        head->nxt = tail;

        mpp.clear();
    }

    void put(int x, int y){
        if(mpp.size()<size){
            Node *newNode = new Node(x, y);

            mpp.insert({x, newNode});

            Node *afterHead = head->nxt;

            head->nxt = newNode;
            newNode->prev = head;
            afterHead->prev = newNode;
            newNode->nxt = afterHead;
        }
        else{
            if(mpp.find(x)!=mpp.end()){}
            else{}
        }
    }  
};