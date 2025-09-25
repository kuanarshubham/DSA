#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    vector<Node*>link;
    bool flag;

    Node(){
        this->link.resize(26, NULL);
        this->flag=false;
    }

    bool containsLetter(char c){
        return link[c - 'a']!=NULL;
    }

    void insertLetter(char ch, Node *node){
        link[ch-'a'] = node;
    }

    Node *getNext(char ch){
        return link[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    void setFlag(){
        flag = true;
    }

    bool getFlag(){
        return flag;
    }
};

class Trie{
    public:
    Node *root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *temp = root;

        int n=word.size();

        for(int i=0; i<n; i++){
            if(!temp->containsLetter(word[i])){
                temp->insertLetter(word[i], new Node());
            }

            temp = temp->getNext(word[i]);
        }

        temp->setFlag();
    }

    bool serach(string word){
        int n=word.size();

        Node *temp = root;

        for(int i=0; i<n; i++){
            if(!temp->containsLetter(word[i])) return false;

            temp = temp->getNext(word[i]);
        }

        return temp->getFlag();
    }

    bool startsWith(string word){
        int n=word.size();

        Node *temp = root;

        for(int i=0; i<n; i++){
            if(!temp->containsLetter(word[i])) return false;

            temp = temp->getNext(word[i]);
        }

        return true;
    }
};



int main(){
    Trie *t = new Trie();

    t->insert("apple");
    t->insert("apps");
    t->insert("apxl");
    t->insert("bat");
    t->insert("bac");

    cout<<t->serach("app")<<endl;
    cout<<t->startsWith("app")<<endl;
    cout<<t->startsWith("ba")<<endl;
    cout<<t->serach("bat")<<endl;
    
}