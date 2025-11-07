#include<bits/stdc++.h>
using namespace std;

bool pr(int n){
    if(n <= 1)return false;


    for(int i = 2 ; i <= n ;i++){
        if(n%i == 0)return false;
    }

    return true;
}


bool p_pr(int n){
    if( n<=1)return false;

    for(int i = 2; i*i <= n;i++){
        if(n%i==0)return false;
    }
    return true;
}

bool ch(int n){
    if(n == 2 || n == 3)return true;

    if(n % 2 == 0 || n % 3 == 0)return false;


    for(int i = 5 ; i * i <= n; i++){
        if(n%i == 0 || n%(i+2) == 0)return false; 
    }
    return true;
}


int main(){
    return 0;
}