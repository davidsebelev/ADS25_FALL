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

// Node* insertAtFront(Node* head,int x){
//     Node* newNode = new Node(x);

//     if(head == nullptr) head = newNode;

//     newNode->next = head;

//     return newNode;
// }


int main(){
    Node* head = nullptr;
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        Node* new_node = new Node(x);

        if(head == nullptr){
            head = new_node;
            cnt++;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
            cnt++;
        }
    }


    // if(cnt%2 == 0){
    //     cnt = (cnt / 2) + 1;
    // }else{
    //     cnt = cnt/2;
    // }

    cout << cnt << "\n";

    Node* curr = head;
    if(cnt%2==0){
        cnt = (cnt / 2) + 1;
        for(int i = 0; i < cnt-1; i++){
        curr = curr->next;
    }
    cout << curr->data;
    }else{
        cnt = cnt/2;
        for(int i = 0; i < cnt; i++){
        curr = curr->next;
        }
        cout << curr->data;
    }
    // for(int i = 1; i < cnt; i++){
    //     curr = curr->next;
    // }



    //cout << cnt;
    return 0;
}