//gcd наибольший общий делитель // самое быстрое решение через алгоритм евклида
#include<iostream>
using namespace std;


// gcd с рекурсией 
int gcd2(int a, int b){
    if(b == 0) return a;
    return gcd2(b, a%b);
}
// gcd без рекурсии тоже быстрое но используется так как в больщих примерах 
// рекурсия может занять очень много места
int gcd1(int a, int b) { 
    while (a > 0 && b > 0) { 
        if (a > b)
            a = a % b;
        else
            b = b % a;        
    }
    return a + b;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd2(a,b) << endl;
    cout << gcd1(a,b) << endl;
    return 0;
}