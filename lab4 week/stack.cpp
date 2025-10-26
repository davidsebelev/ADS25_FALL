#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data  = x;
        next = nullptr;
    }
};

class myStack {
    Node* top;
    
    // To Store current size of stack
    int count;
    
public:
    myStack() {
        
        // initially stack is empty
        top = NULL;
        count = 0;
    }


    void push(int x){
        Node* temp = top;
        temp->next = top;
        top = temp;
        count++;
    }


    int pop(){
        if(top == nullptr) return -1;

        Node* temp = top;
        top = top->next;
        int val = temp->data;
        count--;
        delete temp;
        return val;
        

    }

    int peek(){
        return top->data;
    }

};