// bst realization by me and also with yt vids
#include<iostream>
#include<queue>
using namespace std;


struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BstNode* InsertNewNode(BstNode* root, int data){
    if(root == nullptr) root = GetNewNode(data);
    else if(root->data >= data){
        root->left = InsertNewNode(root->left, data);
    }else{
        root->right = InsertNewNode(root->right, data);
    }
    return root;
}

BstNode* find_min(BstNode* root){
    while(root->left != nullptr) root = root->left;
    return root;
}

BstNode* deletionNode(BstNode* root, int data){
    if(root == nullptr) return root;
    else if(data < root->data) root->left = deletionNode(root->left, data);
    else if (data > root->data) root->right = deletionNode(root->right, data);

    else {
        //1 case when leaf node // no child i mean
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
        }
        // 2 case when 1 child
        else if(root->left == nullptr){
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == nullptr){
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }
        // 3 case with 2 childs
        else {
            BstNode* temp = find_min(root->right);
            root->data = temp->data;
            root->right = deletionNode(root->right, temp->data);
        }
    } 
    return root;
}

bool searchNode(BstNode* root, int val){
    if(root == nullptr) return false;
    else if(root->data == val){
        return true;
    }
    else if(val <= root->data){
        return searchNode(root->left, val);
    }else{
        return searchNode(root->right, val);
    }
}
// нахождение через цикл
int FindMinNode(BstNode* root){
    if(root == nullptr) return -1;

    BstNode* curr = root;
    while(curr->left != nullptr){
        curr = curr->left;
    }

    return curr->data;
}

// нахождение рекурсией
int findNodeMinRec(BstNode* root){
    if(root == nullptr) return -1;
    else if(root->left == nullptr) return root->data;
    return findNodeMinRec(root->left);
}

// find by while
int find_max_node(BstNode* root){
    if(root == nullptr) return -1;

    BstNode* curr = root;
    while(curr->right != nullptr){
        curr = curr->right;
    }
    return curr->data;
}
// find by rec
int find_max_node_rec(BstNode* root){
    if(root == nullptr) return -1;
    else if(root->right == nullptr) return root->data;
    return find_max_node_rec(root->right);
}
// найти длину максимальную бст если захочу найти определенной ноды то нужно root->left->left and etc;
int findHeight(BstNode* root){
    if(root == nullptr) return -1;
    return max(findHeight(root->left),findHeight(root->right)) + 1;
}

void level_order_traversal(BstNode* root){
    if(root == nullptr) return;
    queue<BstNode*> q;
    q.push(root);
    while(!q.empty()){
        BstNode* curr = q.front();
        cout << curr->data << " ";
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
        q.pop();
    }
    cout << "\n";
}

void pre_order(BstNode* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(BstNode* root){
    if(root == nullptr) return;
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void post_order(BstNode* root){
    if(root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}




int main(){
    BstNode* root = nullptr;

    root = InsertNewNode(root, 15);
    root = InsertNewNode(root, 10);
    root = InsertNewNode(root, 20);
    root = InsertNewNode(root, 25);
    root = InsertNewNode(root, 8);
    root = InsertNewNode(root, 12);

    int num;
    cin >> num;
    if(searchNode(root,num)){
        cout << "y" << "\n";
    }else{
        cout << "n" << "\n";
    }
    // cout << FindMinNode(root) << "\n";
    // cout << findNodeMinRec(root) << "\n";
    // cout << find_max_node(root) << "\n";
    // cout << find_max_node_rec(root) << "\n";
    // cout << findHeight(root) << "\n";
    //level_order_traversal(root);
    // pre_order(root);
     in_order(root);
     cout << "\n";
    // post_order(root);

    deletionNode(root,20);

    in_order(root);

}