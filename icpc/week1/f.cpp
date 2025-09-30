#include<iostream>
#include<vector>
using namespace std;


int main(){
    const int MAXN = 1e7;
    vector<bool> primes(MAXN + 1, true);
    primes[0] = primes[1] = false;
    
 
    for(int i = 2 ; i * i <= MAXN ;i++){
        if(primes[i]){
            for(int j = i*i ; j <= MAXN ; j+=i){
                primes[j] = false;
            } 
        }
    }

    int m, n;
    while(cin >> m >> n){
        int cnt = 0;
    for(int i = m; i <= n; i++){
        if(primes[i]) cnt++;
    }
    cout << cnt << "\n\n";
    }
    
    return 0;
  
}