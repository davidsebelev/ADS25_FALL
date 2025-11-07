#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt[4]={0};

    for(int i = 0 ; i < s.size();i++){
        if(s[i]>='1' and s[i]<='3') cnt[s[i]-'0']++;
    }

    bool fl = true;
    for(int i = 1 ;  i <= 3;i++){
        for(int j = 0 ; j < cnt[i];j++){
            if(!fl)cout <<'+';
            cout << i;
            fl = false;
        }
    }

    // string n = "";
    // for(int i = 0 ; i  < s.size();i++){
    //     if(s[i] >= '0' && s[i] <='9')n+=s[i];
    // }
    
    // sort(n.begin(),n.end());
    // //cout << n;
    // for(int i = 0 ; i < n.size();i++){
    //     if(i + 1 == n.size())cout << n[i];
    //     else cout << n[i] << '+';
    // }
    return 0;
}