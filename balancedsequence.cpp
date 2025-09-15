#include<iostream>
#include<stack>
#include<string>
using namespace std;


void checkBalance(string s){
    stack<char> st;
    for(int i = 0 ; i < s.length();i++){
        if(s[i] >= 'a' && s[i] <='z'){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(s[i] == st.top()){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }else{
            return;
        }
    }
    if(st.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }

}

int main(){
    string s;
    cin >> s;
    checkBalance(s);
    return 0;
}