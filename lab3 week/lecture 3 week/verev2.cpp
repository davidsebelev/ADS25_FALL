
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool can_cut(const vector<double>& ropes, double len, int k){
    long long count = 0;
    for(int i = 0 ; i < ropes.size();i++){
        count += (long long) (ropes[i]/len);
    }
    return count >=k;
}

double max_rope_len(const vector<double>& ropes, int k){
    double l = 0, r = *max_element(ropes.begin(), ropes.end());


    for (int iter = 0; iter < 100; iter++) { // enough iterations for precision
        double mid = (l + r) / 2;
        if (can_cut(ropes, mid, k)) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    int n, k;
    cin >> n >> k;


    vector<double> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }
    
    cout << fixed << setprecision(2) << "Max length: " << max_rope_len(ropes, k) << "\n";
    return 0;
}


// r = *max_element(...) — берём верхнюю границу по самой длинной верёвке.
// const vector<double>& — оптимально, чтобы не копировать массив и гарантировать, что функция его не изменит.