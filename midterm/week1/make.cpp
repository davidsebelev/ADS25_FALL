#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;


    stack<char> st;
    for(int i = 0 ; i < s.length();i++){
        if(st.empty()){
            st.push(s[i]);

        }else{
            if(isupper(s[i])){
                if(isupper(st.top())){
                    st.push(s[i]);
                }else{
                    if(toupper(st.top()) == s[i]){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
                }

            }else{
                if(st.top() == toupper(s[i])){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
    }
    vector<char> r;
    while(!st.empty()){
        r.push_back(st.top());
        st.pop();
    }

    for(int i = r.size()-1; i >= 0 ;i--){
        cout << r[i];
    }
    return 0;
}