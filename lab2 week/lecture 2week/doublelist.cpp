#include<iostream>
using namespace std;
// реализация double list 

class Node {
    public:
    int data;

    Node* prev;
    Node* next;
    // создаем начало и конец head and tail 
    Node(int data){
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

int main(){
    Node* head = new Node(10); // сделали голову листа
    head->next = new Node(20); // голова указывает на след элемент листа который равен 10
    head->next->prev = head; // а прыдыдущий на голову 

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data;
        if(temp->next != nullptr) cout << "<->";
        temp = temp->next;
    }

}