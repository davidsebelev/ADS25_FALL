#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n;
    cin >> n;

    if((n & 1) == 0) cout << n / 2;
    else cout << (n/2 + 1)*-1;
    return 0;
}