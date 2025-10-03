// посчитаь высоту правого поддерева и левого 
// самое длинное расстояние между двумя поддеревьями равно
// сумме левого и правого поддерева

#include<iostream>
using namespace std;

class BstNode{
    public:
    int data;
    BstNode* left;
    BstNode* right;
    BstNode(int x){
        data = x;
        left = right = nullptr;
    }
};

BstNode* InsertNewNode(BstNode* root, int data){
    if(root == nullptr) return new BstNode(data);
    else if(data <= root->data) root->left = InsertNewNode(root->left,data);
    else root->right = InsertNewNode(root->right,data);
    return root;
}

int findHeight(BstNode* root){
    if(root == nullptr) return -1;
    else return max(findHeight(root->left), findHeight(root->right)) + 1;
}
int MaxDim = 0;

int maxHeight(BstNode* root){
    if(root == nullptr) return 0;

    int left = maxHeight(root->left);
    int right = maxHeight(root->right);

     MaxDim = max(MaxDim, left + right + 1);

    return max(left,right) + 1;

}


int main(){
    BstNode* root = nullptr;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        root = InsertNewNode(root,x);
    }

    maxHeight(root);
    cout << MaxDim - 1 ;
    return 0;
}