#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

class myQueue{
private:
    Node* front;
    Node* rear;
public:
    myQueue() {
        front = rear = nullptr;
    }
    void Enqueue(int new_d){
        Node* newNode = new Node(new_d);
        if(rear == nullptr){
            rear = front = newNode;
        }
        rear->next = newNode;
        rear = newNode;
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
    int Dequeue(){
        Node* temp = front;
        if(front == nullptr){
            return -1;
        }
        int val = temp->data;
        front = front->next;


        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return val;

    }

    int peek(){
        if(front == nullptr) return -1;
        return front->data;
    }

    bool isEmpty(){
        return front == nullptr;
    }

};

int main(){
    myQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    q.Dequeue();

    cout << q.peek() << endl;


    q.printQueue();

    q.Dequeue();
    q.Dequeue();

    if(q.isEmpty()) cout << "yes";
    return 0;
}