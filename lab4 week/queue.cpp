// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int x){
//         data = x;
//         next = nullptr;
//     }
// };

// class MyQueue{
//     private:
//     int currSize;
//     Node* front;
//     Node* rear;

// public:
//      MyQueue() {
//         currSize = 0;
//         front = rear= nullptr;
//     }

//     bool isEmpty(){
//         return front == nullptr;
//     }

//     void Enqueue(int x){
//         Node* temp = new Node(x);
//             if(front == nullptr){
//                 front = rear = temp;
//             }
//             rear->next = temp;
//             rear = temp;
//         }
    

//     int Dequeue(){
//         if(isEmpty()) return -1;
//         Node* temp = front;
//         int remdata = temp->data;
//         front = front->next;

//         delete temp;
    
//     }


// }