#include<iostream>
#include<vector>
using namespace std;

int sum = 0;
vector<int> r;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};


Node* InsertNewNode(Node* root, int data){
    if(root == nullptr) root = new Node(data);
    else if(data < root->data) root->left = InsertNewNode(root->left,data);
    else root->right = InsertNewNode(root->right,data);
    return root;
}

void  GstBst(Node* root){
    if(root == nullptr) return;

    GstBst(root->right);
    sum+=root->data;
    root->data = sum;

    GstBst(root->left);
}

void Inorder(Node* root){
    if(root == nullptr) return;
    Inorder(root->left);
    r.push_back(root->data);
    Inorder(root->right);
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
    GstBst(root);
    Inorder(root);
    for(int i = r.size() - 1 ; i >= 0;i--){
        cout << r[i ] << " ";
    }
    return 0;
}