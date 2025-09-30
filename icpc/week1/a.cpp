// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int cnt = 0;
//     for(int i = 2 ; i * i <= n ;i++){
//         if(n%i == 0){
//             if(i * i == n){
//                 cnt++;
//             }else{
//                 cnt+=2;
//             }
//         }
//     }
//     cout << cnt;
// }


// количество делителей включая n and 1 
// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int cnt = 0;
    
//     for(int i = 0 ; i*i < n; i++){
//         if(n%i == 0){
//             if(i*i == n) cnt++;
//             else cnt+=2;
//         }
//     }
//     cout << cnt;
// }


// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int cnt = 0;
    
//     for(int i = 1 ; i<= n; i++){
//         if(n%i == 0){
//             cout << i << " ";
//         }
//     }
    
//}

//fast output 

#include<iostream>
using namespace std;
typedef long long ll;


int main(){
    ll n;
    cin >> n;


    vector<ll> res;

    for(ll i = 1; i * i  <= n ;i++){
        if(n%i == 0){
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }

    sort(res.begin(), res.end());

    for(ll i = 0; i < res.size();i++) cout << res[i] << " ";
    return 0;
}