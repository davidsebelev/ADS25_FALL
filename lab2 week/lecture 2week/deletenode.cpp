#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

};

// delete the first el
Node* firstDel(Node* head){
    
    if(head == nullptr){// check if list empty
        return nullptr;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

//delete the last el
// проходимся по всем ел пока след не равен нулю ес
Node* lastDel(Node* head){
    if(head == nullptr) return nullptr; // если список изначально пусто то верни пустоту
    if(head->next == nullptr){ // если один элемен то удаляешь
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while(temp->next->next != nullptr){ // если следующий следующий элемент равен последнуму то ток тогда удаляем
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;

}

void printList(Node* curr){
    while(curr!= nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main(){

    Node* head = new Node(8);
    head->next = new Node(9);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);

    head = lastDel(head);
    printList(head);


}
