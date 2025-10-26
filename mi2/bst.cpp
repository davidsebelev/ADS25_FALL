#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data =x;
        left = right = nullptr;
    }
};

class BST{
    public:
    Node* root;

    BST(){
        root = nullptr;
    }

    //insert
    Node* insert(Node* root, int data){
        if(root == nullptr){
            root = new Node(data);
            return root;
        }

        if(data <= root->data) root->left = insert(root->left,data);
        else root->right = insert(root->right,data);

        return root;
    }

    void inOrder(Node* root){
        if(root == nullptr)return;
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }

    Node *findMin(Node *node) {
        if (node == NULL)
            return NULL;
        while (node->left != NULL)
            node = node->left;
        return node;
    }
};

int main(){
    return 0;
}