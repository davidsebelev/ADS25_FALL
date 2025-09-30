#include<iostream>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node(string x){
        data = x;
        next = nullptr;
    }
};
// class linkedList{
//     private:
//     Node* head;
//     Node* tail;
//     int count;
//     public:
//     linkedList(){
//         head = tail = nullptr;
//         count = 0;
//     }

    
//     void insertAtFront(string x){
//         Node* new_node = new Node(x);
//         new_node->next = head;
//         head = new_node;
//         count++;
//     }
//     void traversalList(){
//         Node* curr = head;
//         while(curr!=nullptr){
//             cout << curr->data << " ";
//             curr = curr->next;
//         }
//         cout << endl;
//     }
//     int sz(){
//         return count;
//     }
//     };


int main(){
    int n, k, cnt = 0;
    cin >> n >> k;
    string s;
    Node* head = nullptr;
    Node* tail = nullptr;

    while(n--){
        cin >> s;
        //заполняем лист словами
        Node* node = new Node(s);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }
    // выводим новое начало 
    Node* current = head;
    while(current != nullptr){
        if(cnt >= k) cout << current->data << " ";
        current = current->next;
        cnt++;
    }
    // выводим новый конец

    cnt = 0;
    current = head;
    while(cnt < k){
        cout << current->data << " ";
        current = current->next;
        cnt++;
    }

    return 0;
}