#include<iostream>
#include<stack>
using namespace std;


void kr(string s){
    stack<char> st;
        for(int i = 0 ; i < s.length();i++){
                if(s[i] == '('){
                    st.push(s[i]);
                }else if(s[i] == ')'){
                    if(st.empty()){
                       cout << "NO";
                       return;
                    }else{
                        st.pop();
                    }
                }
            }

    if(st.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }  
    };


void skob(string s){
    stack<char> st;
    for(int i = 0 ; i < s.length();i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }else{
            if(st.empty()){
                cout << "NO";
                return;
            }else if(st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else if(st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else if(st.top() == '[' && s[i] == ']'){
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    } 
}   

void checkCount(string s){
    int count = 0;
    for(int i = 0 ; i < s.length();i++){
        if(s[i] == '('){
            count++;
        }else{
            count--;
        }
    }

    if(count == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
int main(){
    string sk;
    cin >> sk;
    checkCount(sk);
   

    
}