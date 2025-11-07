#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    // int k, w;
    // long long n;
    // cin >> k >> n >> w;

    // long long sum = 0;
    // for(int i = 1 ; i <= w;i++){
    //     sum += k*i;
    // }

    // if(sum - n < 0)cout << 0;
    // else cout << sum - n;


    // also o(1)

    ll k , n , w;
    cin >> k >> n >> w;


    ll sum = (k * w*(w+1))/2;

    cout << max(0LL,sum - n);

    return 0;
}