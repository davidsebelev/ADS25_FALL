// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i= 0 ; i < n ; i++)cin >> a[i];
//     sort(a.begin(),a.end());
//     reverse(a.begin(),a.end());

//     stack<int> st;

//     int cnt = 0;
//     for(int  i = 1 ; i < n ; i++){
//         if(st.empty()){
//             st.push(a[i]);
//             cnt++;
//         }else{
//             if(a[i] > st.top()){
//                 st.push(a[i]);
//                 cnt++;
//             }
//         }
//     }

//     int s = a[0];
//     int sum = 0;
//     vector<int> r;
//     r.push_back(a[0]);
//     for(int  i = 1 ; i < n ; i++){
//         sum+= a[i]
//         if(a[i] >= s){
//             r.push_back(a[i]);
//             s = a[i];
//         }
//     }

//     cout << r.size();

    
//     return 0;
// }