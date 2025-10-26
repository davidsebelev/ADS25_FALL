#include<bits/stdc++.h>
using namespace std;

bool isInteger(string s) {
    if (s.empty()) return false;

    int start = 0;
    if (s[0] == '-' || s[0] == '+') {
        if (s.size() == 1) return false; // только "-" без цифр
        start = 1;
    }

    for (int i = start; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }

    return true;
}



int main(){
    string s;
    cin >> s;
    vector<string> operations = {"5","2","C","D","+"};
    

    stack<string> st;

    int d_op = 0;
    for(int i = 0 ; i < operations.size();i++){
        if(isInteger(operations[i])){
            st.push(operations[i]);
        }else if(operations[i] == "C"){
            st.pop();
        }else if(operations[i] == "D"){
            d_op = stoi(st.top()) * 2;
            string res = to_string(d_op);
            st.push(res);
        }else if(operations[i] == "+"){ // 5 9
            string temp = st.top();
            st.pop();

            int sum = stoi(temp) + stoi(st.top());
            st.push(temp);

            st.push(to_string(sum));
        }
    }
    int ss = 0;
    while(!st.empty()){
         ss += stoi(st.top());
        st.pop();
    }

    cout << ss;


    return 0;
}