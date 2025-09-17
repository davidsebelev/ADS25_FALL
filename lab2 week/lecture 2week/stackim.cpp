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
class myStack{
private:
    Node* top;
    int sz;
public:
    myStack(){
        top = nullptr;
        sz = 0;
    }

    void push(int new_el){
        Node* new_node = new Node(new_el);
        new_node->next = top;
        top = new_node;
        sz++;
    }
    int del(){
        if(top == nullptr){
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;

        delete temp;
        sz--;
        return value;
    }
    int size(){
        return sz;
    }
    bool isEmpty(){
        return top == nullptr;

    }
    int peek(){
        if(!top) return -1;
        return top->data;
    }



};

int main(){
    return 0;
}