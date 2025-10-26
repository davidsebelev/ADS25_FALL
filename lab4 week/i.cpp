#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int cnt; // сколько раз встречается этот ключ
    Node(int x) {
        data = x;
        cnt = 1; // новая вершина создаётся с 1 копией
        left = right = nullptr;
    }
};

// вставка в BST с учётом кратности
Node* InsertNode(Node* root, int data) {
    if (root == nullptr) return new Node(data);

    if (data < root->data) {
        root->left = InsertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = InsertNode(root->right, data);
    }
    else {
        root->cnt++; // ключ совпал → увеличиваем multiplicity
    }
    return root;
}

// поиск минимального элемента
Node* find_min(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// удаление из BST с учётом кратности
Node* DeletionNode(Node* root, int data) {
    if (root == nullptr) return root;

    if (data < root->data) {
        root->left = DeletionNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = DeletionNode(root->right, data);
    }
    else {
        if (root->cnt > 1) { // если у узла было несколько копий
            root->cnt--;    // просто уменьшаем
            return root;
        }
        // обычное удаление в BST
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = find_min(root->right);
            root->data = temp->data;
            root->cnt = temp->cnt;
            temp->cnt = 1;
            root->right = DeletionNode(root->right, root->data);
        }
    }
    return root;
}

// поиск количества копий элемента
int find(Node* root, int data) {
    if (root == nullptr) return 0;
    if (root->data == data) return root->cnt;
    else if (data < root->data) return find(root->left, data);
    else return find(root->right, data);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;
    int n;
    cin >> n;
    while (n--) {
        string word;
        int x;
        cin >> word >> x;
        if (word == "insert") {
            root = InsertNode(root, x);
        }
        else if (word == "delete") {
            root = DeletionNode(root, x);
        }
        else if (word == "cnt") {
            cout << find(root, x) << "\n";
        }
    }
    return 0;
}
