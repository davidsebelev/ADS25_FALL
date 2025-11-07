#include<bits/stdc++.h>
using namespace std;

int sumIter(int n){
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        sum += (i*i);
    }
    return sum;
}


int sumSq(int n){
    return (n*(n+1)/2)*(2*n+1)/3;
}


int main(){
    int x;
    cin >> x;
    cout << sumSq(x);
    return 0;
}