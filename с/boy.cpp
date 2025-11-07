#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;

    //  set<char> r;

    //  for(int i =  0 ; i < s.size();i++){
    //     r.insert(s[i]);
    //  }

    //  if((r.size()&1)==0)cout << "CHAT WITH HER!";
    //  else cout << "IGNORE HIM!";
    // for(int i = 0 ; i < s.size();i++){
    //     for(int j = i+1 ; j < s.size();j++){
    //         if(s[i]==s[j]){
    //             s[j] = '#';
    //         };
    //     }
    // }

    // for(int i = 0 ; i < s.size();i++){
    //     if(s[i] != '#')cnt++;
    // }

    // if((cnt&1)==0)cout << "CHAT WITH HER!";
    // else cout << "IGNORE HIM!";

    bool seen[26] ={false};

    for(int i = 0 ; i < s.size();i++){
        seen[s[i]-'a'] = true;
    }

    for(int i = 0 ; i < 26 ;i++){
        if(seen[i])cnt++;
    }

    if((cnt&1)==0)cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
    return 0;
}