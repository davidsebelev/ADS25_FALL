// #include<bits/stdc++.h>
// using namespace std;


// class Node{
//     public:
//     int cnt;
//     int data;
//     Node* right;
//     Node* left;

//     Node(int x){
//         data  = x;
//         cnt  = 1;
//         left = right = nullptr;
//     }
// };


// Node* InsertNode(Node* root, int x){
//     if(root == nullptr) root = new Node(x);
//     if(root->data == x) root->cnt++;
//     else if(x < root->data) root->left = InsertNode(root->left,x);
//     else root->right = InsertNode(root->right,x);
//     return root;
// }

// Node* find_min(Node* root){
//     while(root->left != nullptr) root = root->left;
//     return root;
// }

// Node* deleteBst(Node* root, int x){
//     if(root == nullptr) return nullptr;
//     if(x < root->data) root->left = deleteBst(root->left,x);
//     else if(x > root->data) root->right = deleteBst(root->right,x);
//     else{
//         if(root->cnt > 1){
//             root->cnt--;
//             return root;
//         }else if(!root->right){
//             Node* tmp = root->left;
//             delete root;
//             return tmp;
//         }else if(!root->left){
//             Node* temp = root->right;
//             delete root;
//             return tmp;
//         }else{
            
//         }

//     }
// }