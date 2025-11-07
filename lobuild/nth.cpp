#include<bits/stdc++.h>
using namespace std;


int nth(int a, int b,int n){
    int d = b - a;
    int r = a;
    for(int i = 1 ; i  < n ;i++){
        r += d;
    }
    return r;
}

int nthR(int a , int b, int n){
    return (a + (n - 1)*(b - a));
}

int main(){
    int a,b,n;
    cin >> a >> b >> n;
    cout << nth(a,b,n) << "\n";
    cout << nthR(a,b,n) << "\n";
    return 0;
}