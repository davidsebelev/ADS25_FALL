#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};




void NodeReturnWidth(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    int MaxWidth = 0;
    while(!q.empty()){
        int levelD = q.size();
        MaxWidth = max(levelD,MaxWidth);

        for(int i = 0 ; i < levelD;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
    }

    cout << MaxWidth << "\n";
}

int main(){
    int n;
    cin >> n;

    Node* root = nullptr;

    vector<Node*> nodes(n+1);
    for(int i = 1 ; i <= n ;i++) nodes[i] = new Node(i);
    for(int i = 0 ; i < n - 1; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(z == 0) nodes[x]->left =nodes[y];
        else nodes[x]->right = nodes[y];
    }
    NodeReturnWidth(nodes[1]);
    return 0;
}