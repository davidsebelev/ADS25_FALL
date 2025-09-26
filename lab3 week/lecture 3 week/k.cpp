#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

// bool check(vector<int>& pref, int m, int k){
    
// }

// мы ищем минимальный индекс j такой что pref[j] - pref[i] >= k;
// так как j строго правее i следовательно границы l = i +1
// r = n + 1 просто удобнее 

// после бинарного поиска l указывается на минимальный индекс 
// l - i = длина подотрезка
int main(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0 ; i< n  ;i++) cin >> a[i];

    
    //
    vector<long long> pref(n+1, 0);
    for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + a[i];
    }

    int ans = INT_MAX;

    for(int i = 0 ; i < n ;i++){
        long long target = pref[i] + k;

        int l = i + 1;
        int r = n + 1;


        while(l < r){
        int m = (l + r) /2;
        if(pref[m] < target){
            l = m + 1;
        }else{
            r = m;
        }
        }
        if(l <= n && pref[l] >= target){
            ans = min(ans, l - i);
        }
}
 cout << ans << endl;
 return 0;
}
