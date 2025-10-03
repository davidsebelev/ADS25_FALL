#include<iostream>
#include<queue>
using namespace std;

class BstNode{
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


class BstMy{
    public:
    BstNode* root;

    BstMy(){
        root = nullptr;
    }

    // insert operation to left or right depend on value
    // average insert is o(logn) the worst case is o(n);

    BstNode* insertNewNode(BstNode* root, int data){
        BstNode* new_node = new BstNode(data);
        if(root == nullptr) root = new_node;
        else if(root->data >= data){
            root->left = insertNewNode(root->left,data);
        }else{
            root->right = insertNewNode(root->right, data);
        }
        return root;
    }

    // this using for finding link to min root but not for the data find
    BstNode* FindMinNode(BstNode* root){
        while(root->left != nullptr) root = root->left;
        return root;
    }

    // this using for finding link to max root but not for the data find
    BstNode* FindMaxNode(BstNode* root){
        while(root->right != nullptr) root = root->right;
        return root;
    }
    //made find min max by rec and while loop
    int FindMinNodeResRec(BstNode* root){
        if(root == nullptr) return -1;
        else if(root->left == nullptr) return root->data;
        return FindMinNodeResRec(root->left);
    }

    int FindMinNodeRes(BstNode* root){
        if(root == nullptr) return -1;

        while(root->left != nullptr) root = root->left;
        return root->data;
    }

    int FindMaxNodeResRec(BstNode* root){
        if(root == nullptr) return -1;
        else if(root->right == nullptr) return root->data;
        return FindMaxNodeResRec(root->right);
    }

    int FindMaxNodeRes(BstNode* root){
        if(root == nullptr) return -1;
        while(root->right != nullptr) root = root->right;
        return root->data;
    }

    // finding height of node 
    // in our case its height of root
    // height its max path from root to the leaf node
    // leaf height = 0 always
    // to find height of root we need to find max(left,right) + 1;
    // where left is left part of bst and right also

    int FindHeight(BstNode* root){
        if(root == nullptr) return -1;
        return max(FindHeight(root->left),FindHeight(root->right)) + 1;
    }


    //берем рут и его детей , юзаем кью для этого вставляем сначала левого потом правого
    // потом выводим левого и вставляем его детей если такие есть за правым 
    // потом выводим правого и вставляем его детей за детьми левого
    // для этого используем кью как очередь


    void LevelOrderTraversal(BstNode* root){
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
    }

    // now we make pre in rost order
    // pre order node left right
    // in left node right
    // post left right node


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

BstNode* DeletionNode(BstNode* root, int data){
    if(root == nullptr) return root;
    else if(data < root->data) root->left =  DeletionNode(root->left, data);
    else if(data > root->data) root->right = DeletionNode(root->right, data);

    else{
        // 1 case with no child
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }

        // 2 case one child left or right

        else if(root->left == nullptr){
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            BstNode* temp = root;
            root= root->left;
            delete temp;
        }

        // 3 case with 2 child
        else{
            BstNode* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = DeletionNode(root->right, temp->data);
        }
    }
    return root;
}

bool FindNodeBst(BstNode* root, int data){
    if(root == nullptr) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) FindNodeBst(root->left, data);
    else FindNodeBst(root->right,data);
}



};


int main(){
    BstMy *bst = new BstMy();

    bst->root = bst->insertNewNode(bst->root,10);
    bst->root = bst->insertNewNode(bst->root,20);
    bst->root = bst->insertNewNode(bst->root,30);
    bst->root = bst->insertNewNode(bst->root,40);
    bst->root = bst->insertNewNode(bst->root,15);
    bst->root = bst->insertNewNode(bst->root,7);
    bst->root = bst->insertNewNode(bst->root,6);
    bst->root = bst->insertNewNode(bst->root,5);
    bst->root = bst->insertNewNode(bst->root,50);
    bst->root = bst->insertNewNode(bst->root,4);

    bst->in_order(bst->root);
    cout << "\n";
    bst->DeletionNode(bst->root,50);
    bst->pre_order(bst->root);

    
    return 0;
}