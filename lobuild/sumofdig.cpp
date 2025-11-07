#include<bits/stdc++.h>
using namespace std;

int rec(int n){
    if(n == 0)return 0;

    return n%10 + rec(n/10);
}
//firstly n , for ex = 12345
// then s = 1 2 3 4 5 as s[i] all data
//
int sumOf(int n){
    string s = to_string(n);
    int sum = 0;

    for(char ch : s){
        sum += ch - '0';
    }

    return sum;
}

int main(){
    int n;
    cin >> n;

    int s = 0;
    while(n!=0){
        s+= n%10;
        n = n/10;
    }
    cout << s;
    return 0;
}