#include<iostream>
using namespace std;

bool good(long long w, long long h , long long n, long long m){
    return (m / w) * (m / h) >=n;
}

int main(){
//  n прямоугольник w widht and h height
    long long w, h , n;
    cin >> w >> h >> n;

    long long l = 0; // не влезает
    long long r = 1;

    while(!good(w,h,n,r)){
        r *= 2;
    }

    while(l + 1 < r){
        long long m = (l+r)/2;
        if(good(w,h,n,m)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << r << endl;
    


    return 0;
}