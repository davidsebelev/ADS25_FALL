// заполнить бст
// ну создать его конечно сначала
// пройтись по бст
// если узел имеет два ребенка то cnt++;
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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

Node* InsertNode(Node* root, int data){
    if(root == nullptr) return new Node(data);
    else if(data <= root->data) root->left = InsertNode(root->left,data);
    else root->right = InsertNode(root->right,data);
    return root;
};

int LevelOrderTraversal(Node* root){
    if(root == nullptr) return -1;
    queue<Node*> q;

    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        Node* curr = q.front();
        //cout << curr->data << " ";

        if(curr->left != nullptr && curr->right != nullptr){
            cnt++;
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }else{
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        q.pop();
        }
        return cnt;
}

int main(){
    Node* root = nullptr;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        root = InsertNode(root,x);
    }

    cout << LevelOrderTraversal(root);

    return 0;
}