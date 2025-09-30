#include<iostream>
#include<vector>
using namespace std;


const int  MAXN = 1e4;
vector<int> phi(MAXN+1);

vector<long long> pref(MAXN + 1);



void phi_sums(){
    for(int i = 0;  i <=  MAXN; i++) phi[i] = i;

    for(int i = 2 ; i <= MAXN ;i++){
        if(phi[i] == i){
            for(int j = i ; j <= MAXN ; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }

    pref[0] = 0;
    for(int i = 1 ; i <= MAXN ; i++){
        pref[i] = pref[i-1] + phi[i];
    }
}


int main(){

    int t;
    cin >> t;

    phi_sums();
    while(t--){
    int n;
    cin >> n;

    long long ans =  pref[n] * pref[n];
    cout << ans << "\n";
    }
    return 0;
}