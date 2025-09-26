#include<iostream>
#include<vector>
using namespace std;
//думаю сделать вектор с праймами а потом по этому вектору пройтись 
// если индекс не праймовый то не кидать его в новый вектор 
// потом просто проходишься по новому вектору и выводишь его новый индекс то есть индекс суперпрайма


// первый вектор с праймовыми значениями 
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

bool check(int n){
    if(n<2) return false;
    for(int i = 2 ; i * i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    
    return true;
}



int main(){
    int n;
    cin >> n;
    vector<int> result;
    vector<int> res = sieve(100000);
    for(int i = 0 ; i< res.size(); i++){
        if(check(i+1)){
            result.push_back(res[i]);
        }
    }

    cout << result[n-1];
    return 0;

}