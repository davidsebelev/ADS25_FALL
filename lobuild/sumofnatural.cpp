#include<bits/stdc++.h>
using namespace std;

// iterative o(n) time and o(1)space
void sum(int n){
    int sum = 0;
    for(int i = 1 ; i <= n ;i++){
        if(i == n) cout << i << " = ";
        else cout << i << " + ";
        sum +=i;
    }
    cout << sum;
}

//using recursion
// o(n) time and space
int sumRec(int n){
    if(n==1) return 1;
    return n + sumRec(n-1);
}


//using formula
// o(1) time and space
int findSum(int n){return n*(n + 1)/2;};

int main(){
    int n;
    cin >> n;

    cout << findSum(n);
    return 0;
}