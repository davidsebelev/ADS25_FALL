#include<iostream>
using namespace std;

typedef long long ll;
//долго
// void returnNumbers(int last, int first){
//     for(int i = first; i <= last;i++){
//         cout << i;
//         if(i != last) cout << " + ";
//     }
// }


// void returnFL(int n){
//     for(int last = 1 ; last  < n ; last++){
//         for(int first = 0 ;  first < last ; first++){
//             if(2 * n == (last - first) * (last + first + 1)){
//                 cout << n << " = ";
//                 returnNumbers(last, first + 1);
//                 cout << "\n";
//                 return;
//             }
//         }
//     }
//     cout <<  "IMPOSSIBLE\n";
// }


void returnFl(ll n){
    for(ll k = 2; k*(k+1)/2 <= n;k++){
        if((2*n)%k == 0){
            ll temp = (2*n) / k - (k - 1);
            if(temp%2 == 0){
                ll a = temp / 2;
                if(a>=1){
                    cout << n << " = ";
                    for(ll i = 0 ; i < k ; i++){
                        cout << a + i;
                        if(i + 1 != k) cout << " + ";
                    }
                    cout << "\n";
                    return;
                }

            }
        }
    }
    cout << "IMPOSSIBLE\n";

}


int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        returnFl(n);
    }
    return 0;
}