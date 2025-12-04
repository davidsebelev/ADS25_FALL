#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,k;
    cin >> n >> k;

    long long odd_count = (n + 1) / 2;
    long long r = 0;

    // 7 - 1 2 3 4 5 6 7
    // 1 3 5 7
    // 2 4 6 

    // 7 / 2 == 3.5 but in c++ = 3, thus (n+1)/2
    // если число четное то есть после нечетных то
    // 7 - 4 == 3
    // 1 3 5 7 2 4 6
    // 2k = 6 , ans = 6
    

    if(k <= odd_count){
        r = 2*k - 1;
    }else{
        k = k - odd_count;
        r = 2*k;
    }
    cout << r;
    
    return 0;
}