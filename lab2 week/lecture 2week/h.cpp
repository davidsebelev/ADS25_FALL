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

//insert pos
Node* insertElPos(Node* head, int pos, int x){
    Node* new_node = new Node(x);
    if(pos == 0){
        new_node->next = head;
        head = new_node;
        return head;
    }
    Node* cur = head;
    for(int i = 0 ; i < pos - 1; i++) cur  = cur ->next;

    new_node->next = cur->next;
    cur->next = new_node;
    return head;
}

// remove el
Node* delPos(Node* head, int pos){
    Node* cur = head;
    if(pos == 0){
        head = cur->next;
        delete cur;
        return head;
    }

    Node* prev = nullptr;
    for(int i = 0 ; i < pos - 1; i++){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

void printL(Node* head){
    Node* curr = head;
    if(curr == nullptr){
        cout << -1 << endl;
        return ;
    }else{
        while(curr!=nullptr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    }
}


Node* replaceL(Node* head, int p1, int p2) {
    if (head == nullptr) return head;

   
    Node* cur = head;
    for (int i = 0; i < p1; i++) {
        cur = cur->next;
    }
    int val = cur->data;

    
    head = delPos(head, p1);

    
    if (p1 < p2) p2--;

    
    head = insertElPos(head, p2, val);

    return head;
}


// Node* replaceL(Node* head, int p1 , int p2){
//     Node* cur1 = head;
//     Node* cur2 = head;
//     if(head == nullptr) return head;

//     // прошлись и записали наши элементы 
//     for(int i = 0 ; i < p1 - 1; i++){
//         cur1 = cur1->next;
//     }
   

//     for(int i = 0 ; i < p2 - 1; i++){
//         cur2 = cur2->next;
//     }
//     if(cur1 == nullptr || cur2 == nullptr) return nullptr;
//     int temp = cur1->data;
//     cur1->data = cur2->data;
//     cur2->data = temp;

//     return head;

// }
// reverse list 
Node* reverseL(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while(cur != nullptr){
        next = cur->next;
        cur->next = prev;// теперь идем справа налево
        prev = cur; // 
        cur = next;
    }
    return prev;
}

Node* cyclic_left(Node* head, int x){
    if(!head || !head->next) return head;

    int len = 1;
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
        len++;
    }
    x %= len;
    if(x == 0) return head;

    Node* cur = head;
    for(int i = 0 ; i < x - 1 ;i++) cur = cur->next;

    Node* new_head = cur->next;
    cur->next = nullptr;
    tail->next = head;

    return new_head;
}


Node* cyclic_right(Node* head, int x) {
    if (!head || !head->next) return head;

    // считаем длину
    int len = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    x %= len;
    if (x == 0) return head;

    // делаем левый сдвиг на len - x
    int steps = len - x;
    Node* cur = head;
    for (int i = 1; i < steps; i++) cur = cur->next;

    Node* newHead = cur->next;
    cur->next = nullptr;
    tail->next = head;

    return newHead;
}






int main(){
    int cmd;
    Node* head = nullptr;
    Node* tail = nullptr;
    while (cin >> cmd && cmd != 0) {
    if (cmd == 1) { int x, p; cin >> x >> p; head = insertElPos(head, p, x); }
    else if (cmd == 2) { int p; cin >> p; head = delPos(head, p); }
    else if (cmd == 3) { printL(head); cout << endl; }
    else if (cmd == 4) { int p1, p2; cin >> p1 >> p2; head = replaceL(head, p1, p2); }
    else if (cmd == 5) { head = reverseL(head); }
    else if (cmd == 6) { int x; cin >> x; head = cyclic_left(head, x); }
    else if (cmd == 7) { int x; cin >> x; head = cyclic_right(head, x); }
}

    return 0;
}