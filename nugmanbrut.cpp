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
        stack<int> copy = st;
        if(st.empty()){
            temp = x;
            x = -1;
            st.push(temp);
            res.push_back(x);
        }else{
            if(st.top() > x){
                while(!copy.empty()){
                    if(!copy.empty()){
                        if(copy.top() > x && copy.size() > 1){
                            copy.pop();
                        }else if(copy.top() > x && copy.size() == 1){
                            temp = x;
                            x = -1;
                            res.push_back(x);
                            st.push(temp);
                            break;
                        }else if(copy.top() < x){
                            temp = x;
                            x = copy.top();
                            res.push_back(x);
                            st.push(temp);
                            break;
                        }
                    }
                }
                
            }else if(st.top() < x){
                temp = x;
                x = st.top();
                res.push_back(x);
                st.push(temp);
            }
        }


    }

    for(int i = 0; i < res.size();i++){
        cout << res[i] << " ";
    }
}