#include<bits/stdc++.h>
using namespace std;


int main(){
    double n;
    cin >> n;
    double sum = 0;
    for(int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }

    double res = sum /n;
    cout << fixed << setprecision(10) <<  res;

    return 0;
}