#include<bits/stdc++.h>
using namespace std;

// struct nicknames{
//     string first;
//     string second;

//     // nicknames(string a, string b){
//     //     first = a;
//     //     second = b;
//     // }
// };

int main(){
    int n;
    cin >> n;
   //vector<nicknames> a;
    map<string,string> nick;
    for(int i = 0 ;i < n ; i++){
        bool f = false;
        string o,n;
        cin >> o >> n;

        for(auto x : nick){
            if(x.second == o){
               nick[x.first] = n;
               f = true;
            }
        }
        if(!f){
            nick[o] = n;
        }
    }
    cout << nick.size() << "\n";

    for(auto x: nick) cout << x.first << " " << x.second << "\n";
    return 0;
}