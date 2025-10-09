#include<iostream>
using namespace std;


int check_min(int m,int n, int d){
    return m * d >= n;
}

int main(){
    int n,d;
    cin >> n >> d;

    int l = 1;
    int r = n;

    while(l + 1 < r){
        int m = (l + r) / 2;
        if(check_min(m,n,d)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r;
    return 0;
}