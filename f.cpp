// дают число это позиция простого числа а ты должен вывести число просто которое стоит на этой позиции
#include<iostream>
using namespace std;


vector<int> sieveE(int n){
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n ;i++){
        if(isPrime[i]){
            for(int j = i*i ; j <= n ; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n ;i++){
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}



int main(){
    int n;
    cin >> n;

    vector<int> primes = sieveE(1001);

    cout << primes[n-1];

}