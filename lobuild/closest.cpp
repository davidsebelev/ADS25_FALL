#include<bits/stdc++.h>
using namespace std;

// closest to n and divisible by m

int closest(int n , int m){
    int num = 0;
    int maxDif = INT_MAX;


    for(int i = n - abs(m);  i<= n + abs(m);i++){
        if(i % m == 0){
            int dif  = abs(n - i);


            if(dif < maxDif || dif == maxDif && abs(i) > abs(num)){
                maxDif = dif;
                num = i;
            }
        }
    }
    return num;
}


// o1 space and time 
int closestNumber(int n, int m){
    int q = n /m;

    int n1 = q * m;

    int n2 = 0;

    if(n * m > 0){n2 = n*(q+1);}
    else n2  = n*(q-1);

    if(abs(n - n1) < abs(n - n2)){return n1;}
    return n2;
}




int main(){
    int n , m;
    cin >> n >> m;


    //start from n - m to n  + m 
    // for ex 13 - 4 and to 13 + 4
    // from 9 to 17

    cout << closest(n,m) << "\n";
    cout << closestNumber(n,m) << "\n";



    return 0;
}