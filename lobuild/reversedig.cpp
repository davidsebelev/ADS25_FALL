#include<bits/stdc++.h>
using namespace std;

int re(int n){
    string s = to_string(n);

    reverse(s.begin(),s.end());

    n =  stoi(s);
    return n;
}



int main(){
    int n;
    cin >> n;
    // while(n != 0){
    //     int r = n % 10;
    //     cout << r;
    //     n = n /10;
    // }

    cout << re(n);
    return 0;
}