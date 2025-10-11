#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* InsertNewNode(Node* root, int d){
    if(root == nullptr) root = new Node(d);
    else if(d <= root->data) root->left = InsertNewNode(root->left,d);
    else root->right = InsertNewNode(root->right,d);
    return root;
}

void LevelOrder(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        Node* curr = q.front();

        if(curr->left != nullptr && curr->right != nullptr){
            cnt++;
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr)q.push(curr->right);
        }else{
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr)q.push(curr->right);
        }
        q.pop();
    }
    cout << cnt;
}





int main(){
    Node* root = nullptr;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        root = InsertNewNode(root,x);
    }


    LevelOrder(root);
    return 0;
}