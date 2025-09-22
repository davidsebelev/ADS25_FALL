#include<iostream>
#include<cmath>
using namespace std;
//a
// int main(){
//     int a,b ;
//     cin >> a >> b;
//     if(a < b)
//         cout << b;
//     else if(a > b)
//         cout << a;
//     else
//         cout << a;

// }
//b
// int main(){
//     int n;
//     cin >> n;
//     if((n%4 == 0 && n%100 != 0)||n%400 == 0) cout << "YES";
//     else
//         cout << "NO";
// }
//3 
// int main(){
//     int a, b;
//     cin >> a >> b;
//     if ((a == 1 && b == 1) || (a != 1 && b != 1)) {
//     cout << "YES";
// } else {
//     cout << "NO";
// }

// }
//4
// int main(){
//     int n;
//     cin >> n;
//     if(n > 0) cout  << 1;
//     else if(n < 0) cout << -1;
//     else if(!n) cout << 0;
// }
//5
// int main(){
//     int a,b ;
//     cin >> a >> b;
//     if(a < b)
//         cout << 2;
//     else if(a > b)
//         cout << 1;
//     else
//         cout << 0;

// }
//6
// int main(){
//     int a , b ,c;
//     cin >> a >> b >> c;
//     cout << max(a,max(b,c));
// }
//7
// int main(){
//     int x1,y1,x2,y2;
//     cin >> x1 >> y1 >> x2 >> y2;
//     if(x1 == x2 || y1 == y2) cout << "YES";
//     else cout << "NO";
//     return 0;
// }
// 8
// int main() {
//   int a, b, c, d;
//   cin >> a >> b >> c >> d;
//   if(a+b == c+d || a-b == c-d){
//       cout << "YES";
//   }else{
//       cout << "NO";
//   }
//   return 0;
// }
// 9
// int main(){
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     if((a+b == c+d || a-b == c-d) || (a == c  || b == d)) cout << "YES";
//     else cout << "NO";
// }
//10 
// int main() {
//   int a, b, c, d;
//   cin >> a >> b >> c >> d;
//   if(((a+1 ==c || a == c+1) && (b+1 ==d || b == d+1 ) ) || (a == c &&( b-1 == d || b+1 == d))||(b == d && (a-1 ==c || a+1 == c))){
//       cout << "YES";
//   }else{
//       cout << "NO";
//   }
//   return 0;
// }
//11
// int main() {
//   int a, b , c , d;
//   cin >> a >> b >> c >> d;
//   if((a == c+1 && b-2 == d) ||(a+1 == c && b-2 == d) || (a+2 == c && b == d+1) || (a+2 == c && b+1 == d) || (a-2 == c && b == d-1) || (a -2 == c && b-1 == d) || (a == c+1 && b+2 == d) || (a+1 == c && b+2 == d)){
//       cout << "YES";
//   }else{
//       cout << "NO";
//   }
//   return 0;
// }
//12
// можно ли шоколад н м разломить на к долек
// int main() {
//   int n, m, k;
//   cin >> n >> m >> k;
//   if(k <= n*m){
//       if(k%n == 0 or k%m == 0){
//           cout << "YES";
//       }else
//           cout << "NO";
//   }else
//       cout << "NO";
//   return 0;
// }
//13
// int main(){
//     int k;
//     cin >> k;
//     if(k == 1) cout << "YES";
//     else if(k%4  == 0) cout << "YES";
//     else cout << "NO";
//     return 0;
// }
//14
// int main(){
//     int a, b;
//     cin >> a >> b;
//     if(a == b && a==0) cout << "INF";
//     else if(a!= b && a==0) cout << "NO";
//     else if(a!=0){
//         if(-b%a ==0){
//             cout << -b/a;
//         }else{
//             cout << "NO";
//         }
//     } 

// }

//15
// int main(){
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;

    

//     int num1 = a*100 + b;
//     int num2 = c*100 + d;

//     int res = num1-num2;
    
//     int e = res/100;
//     int f = res%100;
//     cout << -e << " " << -f;


    // int e = (-res)%100;
    // if(e%100);
    // if(e > 0){
    //     if(e%100 == 0){
    //     cout << e/100;
    // }
    // }
    // if(e%100 == 0){
    //     cout << e/100;
    // }
   // cout << e;

    // if(res < 0) {
    //     cout << res
    // }
    

    //sdacha
    // int e = a - c;
    // if(e < 0){
    //     cout << -e << " ";
    // }else if(e > 0){
    //     cout << e << " ";
    // }else{
    //     cout << e << " ";
    // }

    // int f = b - d;
    // if(f < 0){
    //     cout << -f << " ";
    // }else if(f > 0){
    //     cout << f << " ";
    // }else{
    //     cout << f;
    // }
//}

// int main(){
//     int n;
//     cin >> n;

//     if(n == 1|| n == 2 || n == 4 || n == 0) cout << "NO";
//     else cout << "YES";
// }

//котлеты
int main(){
    int k, m, n;
    cin >> k >> m >> n;
// k   сколько котлет влезает на сковородку.
// m — сколько минут жарим одну сторону.
// n — сколько котлет всего.

    if(n<=k){
        cout << 2*m;
    }else{
        int sides = 2*n; // допустим у 3 котлет 6 сторон
        int res = (sides+k-1)/k;
        cout << m*res;

    }
   
}