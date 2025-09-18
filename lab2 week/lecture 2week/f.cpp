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

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    while(n--){
        int x;
        cin >> x;
        Node* new_node = new Node(x);
        if(head == nullptr){
            head = tail = new_node;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    int el, pos;
    cin >> el >> pos;
    Node* new_el = new Node(el);
    if(pos == 0){
        new_el->next = head;
        head = new_el;
    }else{
        Node* cur = head;
        for(int i = 0; i < pos - 1; i++ ){
            if(cur == nullptr){
                return 0;
            }
            cur = cur->next;
        }
        if(cur == nullptr){
            return 0;
        }
        new_el->next = cur->next;
        cur->next = new_el;

    }
    

    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}