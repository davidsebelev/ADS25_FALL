#include<iostream>
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

    BstNode* insert(BstNode* root, int data){
        BstNode* new_node = new BstNode(data);
        if(root == nullptr) root = new_node;


    }
};


int main(){
    return 0;
}