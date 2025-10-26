#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int k){
        data = k;
        next = nullptr;
    }
};

Node* insertNodeAtBegin(Node* head, int x){
    Node* new_n = new Node(x);
    new_n->next = head;
    return new_n;
}

Node* insertAtEnd(Node* head,int x){
    Node* new_n = new Node(x);
    
    if(head == nullptr) return new_n;

    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = new_n;
    return head;
}

Node* insertAtPos(Node* head, int pos , int k){
    if(pos < 1) return head;
    if(pos == 1){
        Node* new_n = new Node(k);
        new_n->next = head;
        return new_n;
    }

    Node* temp = head;

    for(int i = 1 ; i < pos - 1 and temp!=nullptr;i++){
        temp = temp->next;
    }

    if(temp == nullptr) return head;

    Node* new_node = new Node(k);

    new_node->next = temp->next;
    temp->next  = new_node;

    return head;
}

Node* DeletePo(Node* head,int pos){
    Node* temp = head;
    if(pos < 1) return 0;
    if(pos == 1){
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;
    for(int i = 1; i < pos;i++){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
}


bool findKey(Node* head, int key){
    Node* curr = head;

    while(curr!=nullptr){

        if(curr->data == key) return true;

        curr= curr->next;

    }

    return false;
}

// class Stack{
//     public:
//     Node* top;
//     int sz;

//     Stack(){
//         top = nullptr;
//         sz = 0;
//     }

//     void push(int k){
//         Node* newNode = new Node(k);
//         newNode->next = top;
//         top = newNode;
//         sz++;
//     }

//     int del()
// }

int main(){
    return 0;
}