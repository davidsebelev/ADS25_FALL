#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    const ll MAXN = 1e7;
    vector<bool> primes(MAXN + 1, true);
    primes[0] = primes[1] = false;

    for(int i = 2; i * i <= MAXN; i++){
        if(primes[i]){
            for(int j = i*i ; j <= MAXN; j+=i){
                primes[j] = false;
            }
        }
    }


    
    vector<int> p;
    for(int i = 2 ; i <= MAXN ; i++){
        if(primes[i]) p.push_back(i);
    }

    //for(int i = 0 ; i < p.size();i++) cout << p[i] << " ";



    // int n;
    // cin >> n;

    int n;
    cin >> n;

    while(n--){
        ll low, high;
        cin >> low >> high;
        bool f = false;
        for(ll i  = low ; i <= high ;i++){
            if(primes[i]) continue;

            for(int j = 0 ; j < p.size() && p[j]*p[j] <= i;j++){
                if(i % p[j] == 0){
                  cout << i << " ";
                  f = true;
                  break; 

                } 
            }
            if(f) break;
        }
    }
}