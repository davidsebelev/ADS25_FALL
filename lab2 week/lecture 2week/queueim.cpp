#include<iostream>
using namespace std;
//queue first in first out fifo

class Node{
public:
   int data;
   Node* next;

   Node(int data){
    this->data = data;
    this->next = nullptr;
   }
};
// front - first el
// rare - last el
class myQueue{
    private:
    Node* front;
    Node* rear;
    public:
    myQueue(){
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty(){
        return front == nullptr;
    }
    // add at the end

    // 10 20 30 40 50
    void enqueue(int new_data){
        Node* new_node = new Node(new_data);
        if(isEmpty()){
            front = rear = new_node;//front = rear = 10;
            return;
        }
        rear->next = new_node;// 10-20
        rear = new_node;
    }

    int dequeue(){
        if(isEmpty()){
            return -1;
        }
        Node* temp = front;// pointer
        int val = temp->data;// 50
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
        return val;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return front->data;
    }



};

int main(){
    myQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.dequeue() << endl; // 30
    return 0;


}