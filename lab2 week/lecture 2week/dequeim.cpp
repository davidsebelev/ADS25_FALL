#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class myDeque{
    private:
    Node* front;
    Node* rear;
public:
    myDeque() { 
        front = rear = nullptr; 
    }

    void insertFront(int data){
        Node* new_node = new Node(data);
        if(!front){
            front = rear = nullptr;
        }else{
            new_node->next = front;
            front->prev = new_node;
            front = new_node; 
        }
    }
    void insertEnd(int data){
        Node* newNode = new Node(data);
        if(rear == nullptr){
            front = rear = nullptr;
        }else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;

        }
    }

    void delFront(){
        if(front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if(front) front->prev = nullptr;
        else rear =nullptr;
        delete temp;
    }


    void deleteRear() {
    if (rear == nullptr) {
        std::cout << "Underflow\n";
        return;
    }
    Node* temp = rear;
    rear = rear->prev;

    if (rear == nullptr) 
        front = nullptr;
    else
        rear->next = nullptr;

    delete temp;
}

};