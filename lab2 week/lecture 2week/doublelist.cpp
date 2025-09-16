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

void forwardTraversal(Node* head){
    Node* current = head;

    while(current!= nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void backwardTraversal(Node* tail){
    Node* curr = tail;

    while(curr!=nullptr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}
// insert at the begin of double list 
// новый элемент станет новым prev а старый элемент новым head все сместится вправо
Node* inserFront(Node* head, int new_d){
    Node* new_node = new Node(new_d);
    new_node->next = head;

    if(head!=nullptr){
        head->prev = new_node;
    }
    return new_node;
}
// insert at the end
Node* insertEnd(Node* head, int new_d){
    Node* new_node = new Node(new_d);
    if(head == nullptr){
        head = new_node;
    }else{
        Node* temp = head;
        while(temp->next!=nullptr){
        temp = temp->next;
        }
    temp->next = new_node;
    new_node->prev = temp;
    }
    
return head;
}
// insert at the specific pos
Node* insertSpec(Node* head, int pos, int new_d){
    Node* new_node = new Node(new_d);
    Node* current = head;
    if(pos == 1){
        new_node->next = head;
        if(head != nullptr){
            head->prev = new_node;
        }
        head = new_node;
        return head;
    }
    for(int i = 1; i < pos - 1 && current!=nullptr; i++){ // if pos = 2
        current = current->next;
    }
    if(current == nullptr){
        cout << "pos out of bound";
        delete new_node;
        return head;
    }

    
    new_node->prev = current;
    new_node->next = current->next;
    current->next = new_node;

    if(new_node->next != nullptr){
        new_node->next->prev = new_node;
    }
    return head;
    // 
}
// deletion first el
Node* delF(Node* head){
    if(head == nullptr){
        return nullptr;
    }
    Node* curr = head;
    head = head->next;

    if(head!= nullptr){
        head->prev = nullptr;
    }
    delete curr;
    return head;
}
// del last el
Node* lastEl(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* curr = head;
    while(curr->next!= nullptr){
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;
    return head;
}
//del the pos el
Node* delPos(Node* head, int pos){
    if(head == nullptr) return head;

    Node* curr = head;

    for(int i = 1;  curr != nullptr && i < pos; i++){
        curr = curr->next;
    }

    if(curr == nullptr) return head;

    
    // if the node to delete is not the first node
    // update previous node's next
    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    // if the node to delete is not the last node
    // update next node's prev
    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    // if deleting the head, move head pointer to next node
    if (head == curr)
        head = curr->next;
        
    delete curr; 
    return head;
        

    
}


void printlist(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;


    //forwardTraversal(head);
    //backwardTraversal(third);
    int x = 100;
    // head = inserFront(head, x);
    // printlist(head);

    // head = insertEnd(head, x);
    // printlist(head);

    head = delF(head);
    printlist(head);

    //head = lastEl(head);
    head = delPos(head, 2);
    printlist(head);



}



// как варик реализации double list
// int main(){
//     Node* head = new Node(10);
//     Node* second = new Node(20);
//     Node* third = new Node(30);

//     head->next = second;
//     head->next->prev = head;

//     second->next = third;
//     third->prev = second;


//     forwardTraversal(head);
// }










// int main(){
//     Node* head = new Node(10); // сделали голову листа
//     head->next = new Node(20); // голова указывает на след элемент листа который равен 10
//     // теперь у нас новый лист где первый элемент равен 10 второй 20
//     head->next->prev = head; // предыдущий теперь равен 10

//     head->next->next = new Node(30); // новый 30 а предыдущий равен 20
//     head->next->next->prev = head->next;

//     head->next->next->next = new Node(40);
//     head->next->next->next->prev = head->next->next;

//     Node* temp = head;
//     while(temp!=nullptr){
//         cout << temp->data;
//         if(temp->next != nullptr) cout << "<->";
//         temp = temp->next;
//     }

// }