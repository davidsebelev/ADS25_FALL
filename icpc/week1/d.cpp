#include<iostream>
using namespace std;


int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b,a % b);
}


// slow
// int main(){
//     // int a, b;
//     // cin >> a >> b;

//     // cout << gcd(a,b);

//     int n,cnt = 0;
//     cin >> n;
//     for(int i = 1 ; i <= n ;i++){
//         for(int j = 1; j <= n/i; j++){
//             if(gcd(i,j) == i) cnt++;
//         }
//     }
//     cout << cnt;
//     return 0;
// }


// int main(){
//     int n;
//     cin >> n;


//     int cnt = 0;
//     for(int i = 1 ; i <= n ;i++){
//         for(int j = i ; j<=n ;j+=i){ // только кратные i 
//             if(gcd(i,j) == i) cnt++;
//         }
//     }
//     cout << cnt;
// }


int main(){
    int n;
    cin >> n;


    int cnt = 0;
    for(int i = 1 ; i <= n; i++){
        cnt += n/i;
    }
    cout << cnt;
}