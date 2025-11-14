#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a ,b ,c;
    cin >> a >> b >> c;

    vector<int> rr(c.size(),0);

    //string r = a + b;
    //cout << r << "\n";
    string rere = "";
    for(int i = 0 ; i < c.size();i++){
        for(int j = 0; j < a.size();j++){
            if(c[i] == a[j]){
                c[i] = '-';
                rere+=a[j];
                a[j] = '-';
            } 
        }
    }

    // cout << c << "\n";
    // cout << b << "\n";

    for(int i = 0 ; i < c.size();i++){
        for(int j = 0; j < b.size();j++){
            if(c[i] == b[j]){
                c[i] = '-';
                rere+=b[j];
                b[j] = '-';
            } 
        }
    }

    // cout << c << "\n";
    // cout << a << " " << b << "\n";
    
    string r = a + b;
    vector<char> aaa;
    for(auto i : r){
        if(i != '-')aaa.push_back(i);
    }

    vector<char> ccc;
    for(auto i : c){
        if(i != '-')ccc.push_back(i);
    }

    if(!aaa.empty() || !ccc.empty()){
        cout << "NO";
    }else{
        cout << "YES";
    }
    return 0;
}