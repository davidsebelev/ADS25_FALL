#include<iostream>
#include<vector>
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

BstNode* InsertNewNode(BstNode* root,int data){
    if(root == nullptr) return new BstNode(data);
    else if(data <= root->data) root->left = InsertNewNode(root->left,data);
    else root->right = InsertNewNode(root->right,data);
    return root;
}


BstNode* mov(BstNode* root, string s){
    for(int i = 0; i < s.size(); i++){
        if(root == nullptr) return nullptr;

        if(s[i] == 'L'){
            if(root->left != nullptr) root = root->left;
            else return nullptr;
        }
        else if(s[i] == 'R'){
            if(root->right != nullptr) root = root->right;
            else return nullptr;
        }
    }
    return root; // возвращаем последний узел
}


// BstNode* Movement(BstNode* root,string s){
//     for(int i = 0 ; i < s.size();i++){
//         if(root != nullptr){
//             if(s[i] == 'L' && root->left != nullptr) root = root->left;
//             else if(s[i] == 'R' && root->right != nullptr) root = root->right;
//             else if(s[i] == 'L' && root->left == nullptr){
//                 return nullptr;
//                 break;
//             }else if(s[i] == 'R' && root->right == nullptr){
//                 return nullptr;
//                 break;
//             }
//         }else{
//             return nullptr;
//             break;
//         }
//     }
//     return root;
// }

int main(){
    BstNode* root = nullptr;
    int n,m;
    cin >> n >> m;

    while(n--){
        int x;
        cin >> x;
        root = InsertNewNode(root,x);
    }
    vector<string> w;
    while(m--){
        string s;
        cin >> s;
        w.push_back(s);
    }

    for(int i = 0 ;i < w.size();i++){
        BstNode* check = mov(root,w[i]);
        if(check!=nullptr) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}