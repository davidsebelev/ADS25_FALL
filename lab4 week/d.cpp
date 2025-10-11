#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* InsertNode(Node* root, int d){
    if(root == nullptr) return new Node(d);
    else if(d <= root->data) root->left = InsertNode(root->left,d);
    else root->right = InsertNode(root->right,d);
    return root;
}

int main(){
    Node* root = nullptr;
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        root = InsertNode(root,x);
    }

    vector<int> res;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int sz = q.size(), s = 0;
        for(int i = 0 ; i < sz;i++){
            Node* curr = q.front();
            s+=curr->data;

            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
            
            q.pop();
        }
        res.push_back(s);
    }  
    cout << res.size() << "\n";

    for(int i = 0 ;i  < res.size();i++){
        cout << res[i] << " ";
    }
    


}