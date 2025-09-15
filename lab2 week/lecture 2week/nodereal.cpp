//реализация node(узла)
//node это просто узел который используется в соединенном списке 
// в node хранятся данные и потом соединяются указателями на следующий элемент узла
//https://media.geeksforgeeks.org/wp-content/uploads/20250901170546665785/link1.webp
#include<iostream>
using namespace std;

class Node {
    public:
    int data;

    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);


    Node* temp = head;
    while (temp!= nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    

}