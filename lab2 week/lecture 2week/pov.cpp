#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node(char x){
        data = x;
        next = nullptr;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node* head = nullptr;
        Node* tail = nullptr;
        map<char,int> fr;
        while(n--){
            char ch;
            cin >> ch;
            Node* node = new Node(ch);
            if(head == nullptr){
                head = tail = node;
            }else{
                tail->next = node;
                tail = node;
            }
            fr[ch]++;
            Node* cur = head;
            while(cur!=nullptr && fr[cur->data] < 2){
                cur = cur->next;
            }
            if(cur == nullptr){
                cout << - 1 << " ";
            }else{
                cout << cur->data << " ";
            }
        }
        cout << endl;

    }
    return 0;
}