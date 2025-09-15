//реализация node(узла)
//node это просто узел который используется в соединенном списке 
// в node хранятся данные и потом соединяются указателями на следующий элемент узла
//https://media.geeksforgeeks.org/wp-content/uploads/20250901170546665785/link1.webp
#include<iostream>
using namespace std;


// то есть сама реализация нода(узла) подрузмевает связи элемента и его адреса
class Node {
    public:
    int data;

    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
}; 

// insert node at front of a linked list
// чтобы добавить новый узел нужно указать next на голову листа и теперь новая голова это
// наш новый узел 

Node* insertAtFront(Node* head, int x){
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
} // time complexity o(1);

void printList(Node* head){
    Node* current = head;
    while(current!= nullptr){
        cout << current->data << " ";
        current = current->next;
    }
}


// insert node at the end of a linked list
// получаем наше значение и проходимся по листу пока следующее не равно нулю
// если следующее равно нулю то теперь следующее равно нашему новому значению

Node* insertAtEnd(Node* head, int x){
    Node* newNode = new Node(x);

    if(head == nullptr) return newNode;

    Node* last = head;
    while(last->next != nullptr){
        last = last->next;
    }

    last->next  = newNode;

    return head;
}

//Insert a node at a specific position in a linked list
// given head pos and value
//create new node find the spoat where it should be placed
//loop throught the list before the next node is not your pos
// ling new node to the next 
Node* insertPos(Node* head, int pos, int val){
    if(pos < 1) return head; // если позиция неккоректна то вовзвращаем список
    if(pos == 1){// если позиция это первый элемент
        Node* newNode = new Node(val);// то первый элемент это тот который мы вставляем
        newNode->next = head;// а последующие это головы листа
        return newNode;
    }
    
    Node* current = head; // 3. создаём указатель на начало списка
    // например 3 и 99
    // выводится 10 20 
    for(int i = 1; i < pos - 1 && current  != nullptr; i++){
        current = current->next; 
    }

    if (current == nullptr) // если до шли до конца раньше то вставка анрилл и прсото выводим
    {
        return head;
    }

     Node* newNode = new Node(val);// новый узел он теперь равен 99
     newNode->next = current->next; // новый узел указывает на следующий 99 после него будет 30
     current->next = newNode; // теперь после 20 пойдет 99

     return head;

    
}





int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    int x = 1;
    //head = insertAtFront(head, x);
    head = insertAtEnd(head, x);


    printList(head);


    
    
    

}