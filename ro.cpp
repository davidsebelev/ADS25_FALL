#include<iostream>
#include<deque>
#include<stack>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n; // 4
    stack<int> st; // 1 2 3 4
    for(int i =  1 ; i <= n ;i++){
        st.push(i);
    }
    deque<int> r;
    while(!st.empty()){
        if(r.empty()){
            r.push_back(st.top());
            st.pop();
        }else{
            r.push_front(st.top());
            st.pop();
            int s = r.front()%r.size();
            for(int i = 0 ; i < s ; i++){
                int temp = r.back();
                r.pop_back();
                r.push_front(temp);
            }
        }
        }

    while(!r.empty()){
        cout << r.front() << " ";
        r.pop_front();
    }
    cout << endl;
    }
    return 0;
}