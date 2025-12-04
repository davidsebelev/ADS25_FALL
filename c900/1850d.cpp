#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n,k;
    cin >> t;
    vector<int> r1,r2;
    while(t--){
        cin >> n >> k;
        int n1 = n;
        vector<int> a1(n);
        stack<int> st1,st2;
        vector<int> b1,b2;

        for(int i = 0 ; i < n ;i++)cin >> a1[i];
        vector<int> a2 = a1;

        sort(a1.begin(),a1.end());

        for(auto i : a1)cout << i << " ";
        cout << "\n";
        for(auto i : a2)cout << i << " ";
        cout << "\n";

        for(int i = 0 ; i < n ; i++){
            if(st1.empty()){
                st1.push(a1[i]);
            }else{
                if(abs(st1.top() - a1[i]) <= k){
                    st1.push(a1[i]);
                }else{
                    while(!st1.empty()){
                        b1.push_back(st1.top());
                        st1.pop();
                    }
                    st1.push(a1[i]);
                }
            }
        }
        r1.push_back(b1.size());


        for(int i = 0 ; i <  n1; i++){
            if(st2.empty()){
                st2.push(a2[i]);
            }else{
                if(abs(st2.top() - a2[i]) <= k){
                    st2.push(a2[i]);
                }else{
                    while(!st2.empty()){
                        b2.push_back(st2.top());
                        st2.pop();
                    }
                    st2.push(a2[i]);
                }
            }
        }
        r2.push_back(b2.size());
    }
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(auto i : r1)min1 = min(i,min1);
    for(auto i : r2)min2 = min(i,min2);

    //1 3 3 4 5 7 8 10 
    //10
    //1 3 3 4 5 7 8


    //8 3 1 4 5 10 7 3 
    //3
    //8 3 1 4 5 10 7
    cout << min(min1,min2) << "\n";
    
    return 0;
}