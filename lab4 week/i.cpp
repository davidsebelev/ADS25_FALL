#include<iostream>
using namespace std;

// multiplicty
// cnt++ if insert
// cnt-- if delete
// cnt if like operation cout cnt;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int cnt = 0;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

Node* InsertNode(Node* root, int data){
    if(root == nullptr){
        Node* NewNode = new Node(data);
        NewNode->cnt = 1;
        return NewNode;
    } 
    else if(data < root->data){
        root->left = InsertNode(root->left,data);
    }
    else if(data > root->data){
        root->right = InsertNode(root->right,data);
    }else root->cnt++;
    return root;
}

Node* find_min(Node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* DeletionNode(Node* root, int data){
    if(root == nullptr) return root;
    else if(data < root->data) root->left = DeletionNode(root->left, data);
    else if (data > root->data) root->right = DeletionNode(root->right, data);

    else{


        if(root->cnt > 1) { // если у узла было несколько копий
            root->cnt--;    // просто уменьшаем
            return root;
        }
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
        }

        else if(root->left == nullptr){
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == nullptr){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->cnt = temp->cnt;
            temp->cnt = 1;
            root->right = DeletionNode(root->right, temp->data);
        }
        return root;
    }
}

int find(Node* root , int data){
    if(root == nullptr) return 0;
    else if(root->data == data) return root->cnt;
    else if(data < root->data) return find(root->left,data);
    else return find(root->right, data);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = nullptr;
    int n;
    cin >> n;
    while(n--){
        string word;
        int x;

        cin >> word >> x;
        if(word == "insert"){
            root = InsertNode(root,x);
        }else if(word == "delete"){
            DeletionNode(root,x);
        }else if(word == "cnt"){
            cout << find(root,x) << "\n";
            //cout << root
        }
    }
    cout.flush();
    return 0;
}