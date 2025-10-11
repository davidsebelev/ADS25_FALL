#include<iostream>
#include<queue>
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

Node* insertNewNode(Node* root,int data){
    if(root == nullptr) root = new Node(data);
    else if(data <= root->data) root->left = insertNewNode(root->left, data);
    else root->right = insertNewNode(root->right, data);
    return root;
}

vector<int> res;

void LeverOrderSum(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;


    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        int sum = 0;
        for(int i = 0;  i < sz ; i++){
        Node* curr = q.front();
        sum+=curr->data;

        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr)q.push(curr->right); 

        q.pop(); 
    }
    res.push_back(sum);
    }
    }

int main(){
    Node* root = nullptr;
    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;
        root = insertNewNode(root,x);
    }

    LeverOrderSum(root);

    cout << res.size() << "\n";

    for(int i = 0 ; i < res.size();i++){
        cout << res[i] << " ";
    }
    
    return 0;
}