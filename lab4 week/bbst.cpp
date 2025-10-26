#include<iostream>
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

Node* NodeInsertNew(Node* root, int data){
    if(root == nullptr) root = new Node(data);
    else if(data <= root->data) root->left = NodeInsertNew(root->left,data);
    else root->right = NodeInsertNew(root->right, data);
    return root;
}

Node* FindMinNode(Node* root){
    while(root->left != nullptr) root = root->left;
    return root;
}

Node* FindMaxNode(Node* root){
    while(root->right != nullptr) root = root->right;
    return root;
}

bool SearchNode(Node* root, int data){
    if(root == nullptr) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return SearchNode(root->left,data);
    else return SearchNode(root->right,data);
}

int FindHeight(Node* root){
    if(root == nullptr) return;
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;
}

void LevelOrderTraversal(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout << curr << " ";
        if(curr->right  != nullptr)q.push(curr->right);
        if(curr->left != nullptr) q.push(curr->left);
        q.pop();
    }
    cout << "\n";
}


void pre_order(Node* root){ // node left right
    if(root == nullptr) return;
    cout << root << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node* root){ // left node right 
    if(root == nullptr) return;
    in_order(root->left);
    cout << root << " ";
    in_order(root->right);
}

void post_order(Node* root){
    if(root == nullptr);
    post_order(root->left);
    post_order(root->right);
    cout << root << " ";
}

Node* find_min(Node* root){
    while(root->left != nullptr) root = root->left;
    return root;
}


Node* deletitonNode(Node* root, int data){
    if(root == nullptr) return root;
    else if(data < root->data) root->left = deletitonNode(root->left,data);
    else if(data > root->data) root->right = deletitonNode(root->right,data);
    else{
        //1 case when leaf node
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
        }

        // 2 case when 1 child left or right
        else if(root->left == nullptr){
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == nullptr){
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        else{
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->right = deletitonNode(root->right, temp->data);
        }
    return root;
    }
}

int main(){
    return 0;
}