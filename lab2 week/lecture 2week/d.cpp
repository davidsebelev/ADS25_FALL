#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

int main(){
    int n;
    cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    map<int, int> m;
    int mx = 0;
    while(n--){
        int x;
        cin >> x;
        Node* node = new Node(x);

        m[x]++;
        mx = max(m[x],mx);
        if(head == nullptr){
            head = tail = node;

        }else{
            tail->next = node;
            tail = node;
        }
    }

    set<int> res;
    Node* curr = head;
    while(curr!= nullptr){
        if(m[curr->data] == mx){
            res.insert(curr->data);
        }
        curr = curr->next;
    }

    for(set<int>::reverse_iterator it = res.rbegin();it != res.rend();it++){
        cout << *it << " ";
    }

}


// // brute force 
// int main(){
//     int n;
//     cin >> n;
//     map<int, int> m; // 1 2 2 9 8 9 6 6 7 6 // 10 el
    
//     while(n--){
//         int x;
//         cin >> x;
//         m[x]++;
//     }
    
//     // int maxx = 0;
//     vector<int> r;
//     for(map<int,int>::iterator it = m.begin(); it!= m.end();it++){
//         r.push_back(it->second);
//     }
//     sort(r.begin(),r.end());
//     reverse(r.begin(),r.end());


//     int max_f = r[0];
//     vector<int> re;
//     re.push_back(max_f);
//     for(int i = 1 ;i < r.size();i++){
//         if(r[i] == max_f) re.push_back(r[i]);
//         //cout << r[i] << " ";
//     }
//     vector<int> ree;
//     for(map<int,int>::iterator it = m.begin(); it!= m.end();it++){
//         for(int i = 0 ;i < re.size();i++){
//             if(re[i] == it->second){
//                 ree.push_back(it->first);
//                 //cout << it->first << " ";
//                 it->second = 0;
//             } 
//     }
//     }

//     reverse(ree.begin(),ree.end());
//     for(int i = 0;i < ree.size();i++){
//         cout << ree[i] << " ";
//     }


//     return 0;
// }
// map arpr
// int main(){
//     int n;
//     cin >> n;
//     map<int,int> freq;
//     int max_freq = 0;
//     while(n--){
//         int x;
//         cin >> x;
//         freq[x]++;
//         if(max_freq < freq[x]){
//             max_freq = freq[x];
//         }
//     }

//     vector<int> modes;
//     for(map<int,int>::iterator it = freq.begin();it!=freq.end();it++){
//         if(max_freq == it->second){
//             modes.push_back(it->first);
//         }
//     }

//     reverse(modes.begin(),modes.end());
//     for(int i = 0; i < modes.size();i++){
//          cout << modes[i] << " ";
//     }

// }