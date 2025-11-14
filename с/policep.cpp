#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> st;
    int t = 0; // t = total sum 
    while(n--){
        int x;
        cin >> x;
        if(st.empty()){
            if(x == -1)t++;
            if(x > 0)st.push(x);
        }else{
            if(st.top() > 0 && x == -1){
                int p = st.top() + x; // sila - 1;
                if(p > 0){
                    st.pop();
                    st.push(p);
                }else{
                    st.pop();
                }
            }else if(st.top() > 0 && x > 0){
                int p_pow = st.top() + x;
                st.pop();
                st.push(p_pow);         
            }
        }
    }
    cout << t;
    
    return 0;
}