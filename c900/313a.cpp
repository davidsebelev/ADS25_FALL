#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    string f = "";
    string s = "";

    for(int i = 0; i < n.size() ; i++){
        if(n[0]=='-'){
        if(i!=n.size()-1)f+=n[i];
        if(i!=n.size()-2)s+=n[i];
        }else{
            cout << n;
            return 0;
        }
    }


    int f_i = stoi(f);
    int s_i = stoi(s);

    cout << max(f_i,s_i);
    
    return 0;
}