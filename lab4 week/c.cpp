#include<iostream>
#include<queue>
using namespace std;

class BstNode {
    public:
    int data;
    BstNode* left;
    BstNode* right;
    BstNode(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

BstNode* InsertNode(BstNode* root, int data){
    if(root == nullptr) return new BstNode(data);
    else if(data <= root->data) root->left =  InsertNode(root->left,data);
    else root->right = InsertNode(root->right, data);
    return root;
}

BstNode* FindNode(BstNode* root, int data){
    if(root == nullptr) return nullptr;
    else if(root->data == data) return root;
    else if(data < root->data) return FindNode(root->left, data);
    else return FindNode(root->right,data);
}

void PreOrder(BstNode* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}



int main(){
    BstNode* root = nullptr;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        root = InsertNode(root,x);
    }
    int d;
    cin >> d;

    
    BstNode* node = FindNode(root,d);

    PreOrder(node);
    return 0;
}