#include<iostream>
#include<climits>
# include <algorithm>
# include <cassert>
using namespace std;

// int main(){
//     // алгоритм кадане
//     int n;
//     cin >> n;
//     vector<int> l;
//     while(n--){
//         int x;
//         cin >> x;
//         l.push_back(x);
//     }
//     int curr_sum = 0;
//     int max_sum  = INT_MIN;
//     // идем и складываем числа если в нашем отрезке появляется минусовое значение следовательно сбрасываем сумму 
//     // и начинаем сначала
//     for(int i = 0 ; i < l.size();i++){
//         curr_sum += l[i]; // 1
//         if(curr_sum > max_sum){
//             max_sum = curr_sum; // 1
//         }
//         if(curr_sum < 0){
//             curr_sum = 0;
//         }
//     }

//     cout << max_sum << endl;
//     return 0;

// }

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

void findMaxSum(Node* head){
    Node* cur = head;
    
    int cur_sum = 0;
    int max_sum = INT_MIN;

    while(cur!= nullptr){
        cur_sum += cur->data;
        if(cur_sum > max_sum){
            max_sum = cur_sum;
        }
        if(cur_sum < 0){
            cur_sum = 0;
        }
        cur = cur->next;    
        }
    cout <<  max_sum;
}

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    while(n--){
        int x;
        cin >> x;
        Node* node = new Node(x);
        if(head == nullptr){
            head = tail = node;
        }else{
            tail->next = node;
            tail = node;
        }
    }

    findMaxSum(head);


}