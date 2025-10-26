#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        prev = next = nullptr;
    }
};

//insert begin 

Node* InsertBegin(Node* head, int x){
    Node* newNode = new Node(x);

    newNode->next = head;
    if(head!=nullptr)head->prev = newNode;
    return newNode;
}

Node* InsertEnd(Node* head, int x){
    Node* newNode = new Node(x);
    if(head==nullptr)return head = newNode;

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* InsertPos(Node* head, int pos, int x){
    Node* newNode = new Node(x);
    if(pos < 1) return;
    if(pos == 1){
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* curr = head;
    for(int i = 1; i < pos - 1 && curr!= nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr){
        delete newNode;
        return head;
    }

    newNode->prev = curr;
    newNode->next = curr->next;

    curr->next = newNode;


    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }

    return head;
}

Node* DelHead (Node* head){
    Node* temp = head;
    head = head->next;

    delete temp;
    head->prev = nullptr;
    return head;
}

Node* DelTail(Node* head){
     Node* curr = head;
     while(curr->next != nullptr){
        curr=curr->next;
     }

     curr->prev->next = nullptr;
     delete curr;
     return head;
}

Node* DelPos(Node* head, int pos){
    Node* curr = head;

    for(int i = 1; i < pos;i++){
        curr = curr->next;
    }

    curr->prev->next  = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    return head;
}

int main(){
    return 0;
}