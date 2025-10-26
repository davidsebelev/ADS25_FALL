#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    stack<char> st;

    for(int i = 0; i < s.length();i++){
        if(st.empty()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }else{
            if(s[i] == ')' && st.top() == '('){
                st.pop();
            }else if(s[i] == '}' && st.top() == '{'){
                st.pop();
            }else if(s[i] == ']' && st.top() == '['){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }

    if(st.empty()) cout << "true";
    else cout << "false";
    return 0;
} //({[)