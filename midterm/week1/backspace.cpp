#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin >> s >> t;

    stack<char> st1;
    stack<char> st2;

    for(int i = 0 ; i < s.length();i++){
        if(st1.empty()){
            st1.push(s[i]);
        }else{
            if(s[i]!='#'){
                st1.push(s[i]);
            }else{
                st1.pop();
            }
        }
    }


    for(int i = 0 ; i < t.length();i++){
        if(st2.empty()){
            st2.push(t[i]);
        }else{
            if(t[i]!='#'){
                st2.push(t[i]);
            }else{
                st2.pop();
            }
        }
    }

    // while(!st1.empty()){
    //     cout << st1.top();
    //     st1.pop();
    // } 

    while(!st1.empty() && !st2.empty()){
        if(st1.top() == st2.top()){
            st1.pop();
            st2.pop();
        }else{
            break;
        }
    }

    if(st1.empty() && st2.empty()) cout << "true";
    else cout << "false";


    return 0;

}