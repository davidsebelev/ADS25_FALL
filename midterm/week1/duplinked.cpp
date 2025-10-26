#include<bits/stdc++.h>
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
    while(n--){
        int x;
        cin >> x;
        Node* new_node = new Node(x);

        if(head == nullptr){
            head = new_node;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    Node* curr = head;
    //vector<int> r;
    //Node* prev = nullptr;
    Node* temp = nullptr;
    while(head->next != nullptr){
        if(head->data == head->next->data){
            temp = head->next;
            head->next = head->next->next;
            delete temp;
        }else{
            temp = temp->next;
        }
    }

    


    return 0;
}