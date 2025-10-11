#include<bits/stdc++.h>
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

Node* InsertNode(Node* root,int data){
    if(root == nullptr) root = new Node(data);
    else if(data <= root->data) root->right = InsertNode(root->right,data);
    else root->left = InsertNode(root->left,data);
    return root;
}

void in_order(Node* root, int &sum){
    if(root == nullptr) return;
    in_order(root->left, sum);
    sum+=root->data;
    cout << sum << " ";
    in_order(root->right, sum);
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
    int sum = 0;
    in_order(root, sum);
    return 0;

}