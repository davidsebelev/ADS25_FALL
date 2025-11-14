// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0 ; i < n ;i++)cin >> a[i];

//     int maxx = INT_MIN;
//     int minn = INT_MAX;
//     for(int i = 0 ; i < n ;i++){
//         maxx = max(maxx,a[i]);
//         minn = min(minn,a[i]);
//     }

//     cout << maxx <<   " "  << minn << "\n";

//     int max_i = 0;
//     int min_i = 0;

//     for(int i = 0 ; i < n ;i++){
//         if(a[i] == maxx){
//             max_i = i;
//         }
//         else if(a[i] == minn){
//             min_i = i;
//         }
//     }

//     cout << max_i << " " << min_i <<"\n";

//     int cnt = 0;
//     bool fl = true;
//     for(int i = max_i ; i != 0;i--){
//         swap(a[max_i],a[max-1])
//     }

//     for(int i = 0 ; i < n ; i++) cout << a[i] << " ";

//     cout << "\n";

//     cout << cnt;


//     // int cnt = 0;


    

//     // int cnt = 0;
//     // int i = 0;
//     //     while(max_i != 0){
//     //         swap(a[max_i],a[i]);
//     //         max_i = i;
//     //         cnt++;
//     //         i++;
//     //     }


//     // cout << cnt;
//     // cout <<"\n";

//     // for(auto i : a) cout << i << " ";
    
    
//     return 0;
// }