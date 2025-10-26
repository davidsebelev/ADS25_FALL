#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include <climits>
using namespace std;


// проходимся по массиву размер н 
// создаем разницу нашего числа и элемента массива и записываем ее
// закидываем каждую разницу в какой нибудь массив резалта 

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
    int n, k, pos, count = 0;
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

     Node* curr = head;

    cin >> k;
    int small = INT_MAX;
    vector<int> r;
    while(curr!= nullptr){
        int raz = abs(curr->data - k); // 5
        if(raz < small){         
          small = raz; // 
          pos = count;
        }
        curr = curr->next;
        count++;
    }
    cout << pos;
}

