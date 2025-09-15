#include<iostream>
using namespace std;

// // мое решето юзабельно ток для вывода простых чисел
// void eratos(int n){
//     vector<bool> primes(n+1, true);

//     for(int i = 2 ;  i*i <= n ; i++){
//         if(primes[i]){
//             for(int j = i*i ; j <= n; j = i+j){
//                 primes[j] = false;
//             }
//         }
//     }

//     for(int i  = 2 ; i <=n ; i++){
//         if(primes[i]){
//             cout << i << " ";
//         }
//     }
// }

vector<int> sieve(int limit){
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;
    
    for(int i =  2; i * i <= limit; i++){
        if(isPrime[i]){
            for(int j = i*i ; j <= limit ; j += i){
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    return primes;

}

// //prime factorization its process of breaking a number into a prod of prime nums
// // basis implementation 
// // good for small numbers thats why its slow decision
// void primeFact(int n){
//     for(int i = 2; i*i <= n ;i++){
//         while(n%i == 0){
//             cout << i << " ";
//             n = n/i;
//         }

//     }
//     if(n>1) cout << n;
//     cout << endl;
// }

//fast  thing using precomputed primes
void primeFactorization(int n, const vector<int>& primes){
    int temp = n;
    for(int i = 0 ; i< primes.size();i++){
        int p = primes[i];
        if(p*p > n) break;
        while(n%p == 0){
            cout << p << " ";
            n = n/p;
        }
    }
    if(n>1) cout << n;
    cout << endl;

}

int main(){
    int n;
    cin >> n;

    int lim = (int)(sqrt(n)) + 1;
    vector<int> primes = sieve(lim);

    primeFactorization(n,primes);
    
}