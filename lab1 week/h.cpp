#include<iostream>
#include<vector>
using namespace std;


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


// int main(){
//      int n;
//      cin >> n;
//      bool fl =false;
     
//      vector<int> primes = sieve(1000000);
//      for(int i = 0 ; i < primes.size();i++){
//         if(primes[i]%n == 0 && n != 1 && n != 0){
//             fl = true;
//         }
//      }
//      if(fl){
//         cout << "YES";
//      }else{
//         cout << "NO";
//      }

// }



// #include <iostream>
// #include <vector>
// using namespace std;

// vector<bool> sieve(int limit) {
//     vector<bool> isPrime(limit + 1, true);
//     isPrime[0] = isPrime[1] = false;
    
//     for (int i = 2; i * i <= limit; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j <= limit; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     return isPrime;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<bool> isPrime = sieve(1000000);

//     if (n > 1 && isPrime[n]) cout << "YES";
//     else cout << "NO";
// }
