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

    // заполняем наш лист
    while(n--){
        int x;
        cin >> x;
        Node* new_node = new Node(x);
        if(head == nullptr){
            head = tail = new_node;
        }
        tail->next = new_node;
        tail = new_node;
    }
    // проходимся по листу
    int count = 1;
    Node* cur = head;
    while(cur!=nullptr){
        if(count%2!=0){
            cout << cur->data << " ";
            count++; // 2
            cur = cur->next; // 2
        }else{
            count++;
            cur = cur->next;
        }

    }
    return 0;
}