#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main(){
    int n;
    cin >> n;

    stack<int> st;
    vector<int> res;


    for(int i = 0 ; i < n ;i++){
        int temp;
        int x;
        cin >> x;

        while (!st.empty() && st.top() >= x) {
            st.pop();
        }

        if(st.empty()){
            res.push_back(-1);
        }else if(!st.empty() && st.top() <= x){
            res.push_back(st.top());

        }
        st.push(x);
        
}
for(int i = 0; i < res.size();i++){
        cout << res[i] << " ";

}
}