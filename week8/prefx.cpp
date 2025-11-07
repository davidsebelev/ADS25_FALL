#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pre(n);

    pre[0] = 0;
    for(int i = 1; i < n ;i++){
        int j = pre[i-1];

        while(j > 0 && s[i]!=s[j]){
             j = pre[j-1];
        }

        if(s[i] == s[j]){j++;}
        pre[i] = j;
    }
    return pre;
}


int main(){
    string s;
    cin >> s;

    vector<int> p = prefix_function(s);
    for(int i = 0 ; i < p.size();i++)cout << p[i] << " "; 
    return 0;
}