#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* balanced_tree(vector<int> &a, int l, int r){
    if(l > r) return nullptr;

    int m = (l + r)/2;

    Node* root = new Node(a[m]);
    root->left = balanced_tree(a,l,m-1);
    root->right = balanced_tree(a,m + 1,r);

    return root;

}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    Node* root = balanced_tree(arr, 0, n - 1);

    preorder(root);
    cout << "\n";
}