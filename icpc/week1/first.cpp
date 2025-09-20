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
int main(){
    int k;
    cin >> k;
    if(k == 1) cout << "YES";
    else if(k%4  == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
