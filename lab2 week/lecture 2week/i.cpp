#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(string x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

int cnt = 0;

Node* add_front(Node* head, string x) {
    Node* new_node = new Node(x);
    new_node->next = head;
    if (head != nullptr) {
        head->prev = new_node;
    }
    cnt++;
    return new_node; 
}

Node* add_back(Node* head, string x) {
    Node* new_node = new Node(x);
    if (head == nullptr) {
        cnt++;
        return new_node; 
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new_node;
    new_node->prev = cur;
    cnt++;
    return head;
}

Node* erase_front(Node* head) {
    if (head == nullptr) {
        cout << "error" << endl;
        return nullptr;
    }
    cout << head->data << endl;
    Node* tmp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete tmp;
    cnt--;
    return head;
}

Node* erase_end(Node* head) {
    if (head == nullptr) {
        cout << "error" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        cout << head->data << endl;
        delete head;
        cnt--;
        return nullptr;
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cout << cur->data << endl;
    cur->prev->next = nullptr;
    delete cur;
    cnt--;
    return head;
}

string front(Node* head) {
    if (head == nullptr) return "error";
    return head->data;
}

string back(Node* head) {
    if (head == nullptr) return "error";
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    return cur->data;
}

bool empty() {
    return cnt == 0;
}

Node* clear(Node* head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        cnt--;
    }
    cout << "ok" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;
    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string book; cin >> book;
            head = add_front(head, book);
            cout << "ok" << endl;
        }
        else if (s == "add_back") {
            string book; cin >> book;
            head = add_back(head, book);
            cout << "ok" << endl;
        }
        else if (s == "erase_front") {
            head = erase_front(head);
        }
        else if (s == "erase_back") {
            head = erase_end(head);
        }
        else if (s == "front") {
            if (empty()) cout << "error" << endl;
            else cout << front(head) << endl;
        }
        else if (s == "back") {
            if (empty()) cout << "error" << endl;
            else cout << back(head) << endl;
        }
        else if (s == "clear") {
            head = clear(head);
        }
        else if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}
