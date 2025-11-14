#include <bits/stdc++.h>
using namespace std;

vector<int> pre_f(string s){
    int n = s.size();
    vector<int> p(n);

    for(int i =  1; i < n ;i++){
        for(int len = 1 ; len <=i;len++){
            if(s.substr(0,len) == s.substr(i-len + 1,len)){
                p[i] = len;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> p = pre_f(s);

    for(int i  = 0 ; i < s.size();i++)cout << p[i] << " ";
    
    return 0;
}