// #include<bits/stdc++.h>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int x){
//         data = x;
//         next = nullptr;
//     }
// };

// int main(){
//     int n,m;
//     cin >> n >> m;

//     vector<int> f(n);
//     vector<int> s(m);

//     for(int i = 0 ; i < n ;i++) cin >> f[i];
//     for(int i = 0 ; i < m ;i++) cin >> s[i];

//     for(int i = 0 ; i < m ;i++){
//         f.push_back(s[i]);
//     }

//     for(int i = 0 ; i < f.size();i++) cout << f[i] << " ";

//     sort(f.begin(),f.end());

//     Node* head = nullptr;
//     int x;
//     cin >> x;
//     Node* new_node = new Node(x);

//     if(head == nullptr) head = newNode;


//     return 0;
// }