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

void LevelOrderTraversal(BstNode* root){
    if(root == nullptr) return;
    queue<BstNode*> q;
    q.push(root);
    int cnt = 0;

    while(!q.empty()){
        BstNode* curr = q.front();
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
        cnt++;
        q.pop();
    }
    cout << cnt << "\n";
}

BstNode* InsertNewNode(BstNode* root, int data){
    BstNode* newNode = new BstNode(data);
    if(root == nullptr) root = newNode;
    else if(newNode->data <= root->data) root->left = InsertNewNode(root->left,data);
    else root->right =  InsertNewNode(root->right,data);
    return root;
}

void InOrder(BstNode* root){
    if(root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

BstNode* findNode(BstNode* root, int data){
    if(root == nullptr) return nullptr;
    else if(root->data == data) return root;
    else if(data < root->data) return findNode(root->left,data);
    else return findNode(root->right,data);
}

int main(){
    BstNode* root = nullptr;
    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;

        root = InsertNewNode(root,x);
    }

    int data;
    cin >> data;
    BstNode* node = findNode(root,data);


    LevelOrderTraversal(node);
    return 0;
}

