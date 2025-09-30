#include<iostream>
using namespace std;
typedef long long ll;



int phi (ll n) {
	ll result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main(){
    ll n;
    while(cin >> n && n!=0){
        cout << phi(n) << "\n";
    }
}

// int main(){
//     int t;
//     while(cin >> t){
//         if(t == 0){
//             break;
//         }
//        ll n;
//     cin >> n;

//     // ll res = n;
//     // for(ll i = 2 ; i * i <= n; i++){
//     //     //ll res = n;
//     //     if(n % i  == 0){
//     //         while(n%i == 0){
//     //             n /= i;
//     //         }
//     //         res -= res/i;
//     //     }        
//     // }
//     // if(n > 1){
//     //         res -= res / n;
//     //     }

//     // cout << res << "\n"; 
//     // }
//     //cout << phi(n);
//     return 0;
// }