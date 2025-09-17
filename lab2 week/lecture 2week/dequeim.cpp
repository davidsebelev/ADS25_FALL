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
    myDeque(){
        front = rear = nullptr;
    }
    
    void insertFront(int x){
        Node* new_node = new Node(x);
        if(!front){
            front = rear = new_node;
        };
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    }

    void insertEnd(int x){
        Node* new_node = new Node(x);
        if(!rear){
            front = rear = new_node;
        }
        new_node->prev = rear;
        rear->next = new_node;
        rear = new_node;
    }


    void printQueue(){
        Node* curr = front;
        while (curr!=nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    int delFront(){
        if(!front) return -1;

        Node* temp = front; // 
        front = front->next;
        if(front){
            front->prev = nullptr;
        }else{
            rear = nullptr;
        }
        int value = temp->data;
        delete temp;
        return value;
    }

    int delRear(){
        if(!front) return -1;
        Node* temp = rear;
        rear = rear->prev;
        if(rear){
            rear->next = nullptr;
        }else{
            front = nullptr;
        }
        int value = temp->data;
        delete temp;
        return value;
    }
};



int main(){
    myDeque d;
    d.insertFront(10);
    d.insertFront(20);
    d.insertFront(30);


    d.insertEnd(40);
    d.insertEnd(50);

    d.printQueue();


    d.delFront();
    d.printQueue();

    d.delRear();
    d.printQueue();
    return 0;
}