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

// del the el by pos
Node* delPos(Node* head, int pos, int val){
    //if(pos < 1) return head;
    Node* temp = head;
    if(pos == 1){
        head = temp->next; // новая голова это след элемент
        delete temp; // удаляем старую голову 
        return head; // ну и вовзращем новую
    }
    
    Node* prev = nullptr;
    for(int i = 1; i < pos ;i++){
       prev = temp; // прев указывает на предыдущий элемент
       temp = temp->next; // тут просто сдвиг
    }

    prev->next = temp->next; // перепрыгиваем через удаляемый элемент
    delete temp; //
    return head;

}
// finding el in linked list 
bool findEl(Node* head, int el){
    Node* newEl = new Node(el);

    Node* curr = head;
    while(curr!=nullptr){
        if(curr->data == el){
            return true;
        }
        curr = curr->next;
    }

    return false;
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
    int x = 10;
    if(findEl(head,x)){
        cout << "y";
    };

    //head = lastDel(head);
    //printList(head);


}
