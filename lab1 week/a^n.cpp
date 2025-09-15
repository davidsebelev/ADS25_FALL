#include<iostream>
#define ll long long
using namespace std;


ll bigPow(ll a,ll n){ // 2 4 
    if(n == 0){
        return 1;
    }
    if(n%2 == 0){ // 4 del
        return bigPow(a*a, n/2); // 4 and 2 // 16 and 1
    }else{
        return a*bigPow(a,n-1); // 16 and 0 then return 
    }
}

// Iterative version
ll binpow_iter(ll a, ll n) { // 2 and 3
    ll  result = 1;
    while (n > 0) {
        if (n % 2 == 1) { // 3 odd 
            result *= a; // 8
        }
        a *= a; // 4
        n /= 2;  // 1
    }
    return result;
}



int main(){
    ll a,n;
    cin >> a >> n;
    cout << bigPow(a,n) << endl;
    cout << binpow_iter(a,n) << endl;
    return 0;
}