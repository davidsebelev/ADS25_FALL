// #include <iostream>
// #include <vector>
// using namespace std;

// // const int inf = (1ll << 30) - 1;  // здесь вообще не используется
// // const int N = (int)1e6 + 10;      // и это тоже не нужно

// // int a[N]; // не используется
// int n, q; // q не используется

// int main() {
//     cin >> n;

//     vector<pair<int,int> > ans; // сюда сохраняем множители и их степени

//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0) {
//             int alpha = 0;
//             while (n % i == 0) {
//                 n /= i;
//                 alpha++;
//             }
//             ans.push_back(make_pair(i, alpha));
//         }
//     }

//     if (n > 1) {
//         ans.push_back(make_pair(n, 1));
//     }

//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i].first;
//         if (ans[i].second > 1) {
//             cout << "^" << ans[i].second;
//         }
//         if (i + 1 != ans.size()) {
//             cout << "*";
//         }
//     }

//     cout << "\n";

//     return 0;
// }


// prime check

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool fl = false;
    for (int i = 2 ; i*i <= n ; i++)
    {
        if(n%i == 0){
            fl = true;
            break;
        }
    }

    if(fl || (n == 0 || n == 1)){
        cout << "no" << endl;
    }else{
        cout << "yes" << endl;
    }
    
    return 0;
}

// int main(){
//     int n;
//     cin >> n;

//     vector<bool> primes (n + 1, true);

//     primes[0] = primes[1] = false;
// //13
//     for (int i = 2 ; i*i <= n ; i++){
//         if(primes[i]){
//             for(int j = i * i ; j <=n ; j +=i){
//                 primes[j] = false;
//             }
//         }
//     }

//     vector<int> res;

//     for(int i = 2 ; i < n ;i++){
//         if(primes[i]) cout << i << " ";
//         //cout << primes[i] << endl;
//     }

//     // bool fl = true;
//     // for (int i = 0 ; i < n ; i++){
//     //     if(primes[i] == n){
//     //         fl = false;
//     //         break;
//     //     } 
//     //     else fl = true;
//     // }

//     // if(!fl){
//     //     cout << "yes" << endl;
//     // }else{
//     //     cout << "no" << endl;
//     // } 
// }