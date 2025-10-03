#include<iostream>
#include<queue>
#include<vector>
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

// Node* InsertNew(Node* root, int data){
//     if(root == nullptr) return new Node(data);
//     else if(data == 0) r;
// }

Node* InsertNode(Node* root, int data){
    if(root == nullptr) return new Node(data);
    else if(data <= root->data) root->left = InsertNode(root->left,data);
    else root->right = InsertNode(root->right,data);
    return root;
}

int LevelOrderTraversal(Node* root){
    if(root == nullptr) return -1;
    queue<Node*> q;
    q.push(root);

    int maxWidth = 0;

    while(!q.empty()){
        int size = q.size();
        maxWidth = max(maxWidth,size);

        for(int i = 0; i < size; i++){   // перебираем все вершины уровня
        Node* curr = q.front(); q.pop();
        //cout << curr->data << " ";   // если хочешь печатать узлы

        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
    }
    }
    return maxWidth;
}

int main(){
    Node* root = nullptr;
    int n;
    cin >> n;

    vector<Node*> nodes(n+1);
    for(int i = 1 ; i <= n ; i++) nodes[i] = new Node(i);
    for(int i = 0 ; i < n-1;i++){
        int x,y,z;
        cin >> x >> y >> z;

        if(z == 0) nodes[x]->left = nodes[y];
        else nodes[x]->right = nodes[y];
    }


    cout << LevelOrderTraversal(nodes[1]);


    return 0;

}