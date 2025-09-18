#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node(string name){
        data = name;
        next = nullptr;
    }
};

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    while(n--){
        string name;
        cin >> name;
        Node* new_node = new Node(name);
        if(head == nullptr){
            head = tail = new_node;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
    }

    Node* cur = head;
    int count = 0;
    vector<string> r;
    while(cur!= nullptr){
        if(cur->next!= nullptr){
            if(cur->data != cur->next->data){
            r.push_back(cur->data);
            //cout << cur->data << endl;
            cur = cur->next;
            count++;
        }else{
            cur = cur->next;
        }
        }else{
            r.push_back(cur->data);
            //cout << cur->data << endl;
            cur = cur->next;
            count++;
        }
        
    }
    
    cout << "All in all: " << count << endl;
    cout << "Students:" << endl;

    reverse(r.begin(),r.end());
    for(int i = 0 ; i < r.size();i++){
        cout << r[i] << endl;
    }


    return 0;
}

// int main(){
//     int n;
//     cin >> n;
//     set<string> s;
//     while(n--){
//         string x;
//         cin >> x;
//         s.insert(x);
//     }

//     cout << s.size() << endl;
//     vector<string> names;
//     for(set<string>::iterator it = s.begin();it!=s.end();it++){
//         names.push_back(*it);
//     }
//     //reverse(names.begin(), names.end());
//     for(int i = 0 ; i < names.size();i++){
//         cout << names[i] << " ";
//     }
// }