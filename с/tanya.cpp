#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    while(k--){
        int l = n%10;

        if(l != 0){
            n = n-1;
        }else{
            n = n/10;
        }
    }

    cout << n;
}