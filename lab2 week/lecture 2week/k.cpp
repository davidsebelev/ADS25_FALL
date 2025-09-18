// #include<iostream>
// using namespace std;


// class Node{
//     public:
//     char data;
//     Node* next;
//     Node(char x){
//         data = x;
//         next = nullptr;
//     }
// };


// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         Node* head =nullptr;
//         Node* tail = nullptr;
//         while(n--){
//             char ch;
//             cin >> ch;
//             Node* new_node = new Node(ch);
//             if(head == nullptr){
//                 head = tail = new_node;
//             }else{
//                 tail->next = new_node;
//                 tail = new_node;
//             }
//         }
//         Node* curr = head;
//         char val = curr->data;
//         cout << val << " ";
//         curr = curr->next;

//         while(curr!=nullptr){
//                 if(curr->data != val){
//                 cout << val << " ";
//                 curr = curr->next
//                 }else{
//                     cout << -1 << " ";
//                     val = curr->next->next->data;
//                     curr = curr->next;
            
//         }
//     }
//     return 0;
// }