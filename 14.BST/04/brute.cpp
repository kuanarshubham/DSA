#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left, *right;

    Node(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* addNode(Node *root, int x){
    Node *newNode = new Node(x);
    if(root == NULL) return newNode;
    
    Node *temp = root;

    while(true){
        if(x > temp->val){
            if(temp->right!=NULL) temp = temp->right;
            else{
                temp->right = newNode;
                break;
            }
        }
        else if(x < temp->val){
            if(temp->left != NULL) temp = temp->left;
            else{
                temp->left = newNode;
                break;
            }
        }
    }

    return root;
}

void traversal(Node *root){
    if(root==NULL) cout<<"No value"<<endl;

    queue<Node*> q;
    vector<int> v;

    q.push(root);

    while(!q.empty()){
        Node *frontVal = q.front();

        if(frontVal->left) q.push(frontVal->left);
        
        if(frontVal->right) q.push(frontVal->right);

        v.push_back(frontVal->val);
        q.pop();
    }

    for(auto it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(5);
    Node *n1 = new Node(2);
    Node *n2 = new Node(8);
    //Node *n3 = new Node(2);
    Node *n4 = new Node(4);

    head->left = n1;
    head->right = n2;
    //n1->left = n3;
    n1->right = n4;

    traversal(head);
    traversal(addNode(head, 3));

}