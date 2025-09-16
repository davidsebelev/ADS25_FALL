#include<iostream>
using namespace std;
// stack lifo last in fist out

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class myStack {
    // making pointer to the top
    Node* top;

    int count;
public:
myStack(){
    // initially stack is empty
    top = nullptr;
    count = 0;

}
void push(int x) {
    Node* temp = new Node(x);
    temp->next = top;
    top = temp;
    count++;
}
// deleting top el
int del(){
    if(top == nullptr) return -1;
    Node* temp = top;
    top = top->next;
    int val = temp->data;
    delete temp;
    return val;
}

int peek(){
    if(top == nullptr) return -1;
    return top->data;
}
bool isEmpty(){
    return top == nullptr;
}
int size(){
    return count;
}

};



int main(){
    myStack st;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        st.push(x);
    }

    for(int i = 0 ; i < st.size();i++){
        cout << st.peek() << " ";
        st.del();
    }
    return 0;
}