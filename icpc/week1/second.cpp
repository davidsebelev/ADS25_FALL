#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//3
// int main(){
//     long long a, b;
//     cin >> a >> b;
//     //
//     for(int i = a ; i<=b;i++){
//         int r = sqrt(i);
//         if(r*r  == i) cout << i << " ";
//     }
// }
//4
// int main(){
//     int x, d;
//     cin >> x >> d;
//    // string num = to_string(x);
//     int count = 0;
//     while(x!=0){
//         int c = x%10;
//         if(c == d) count++;
//         x = x/10;
//     }
//     cout << count;
// }
//5
// int main(){
//     int n;
//     cin >> n;
//     int sum = 0;
//     while(n!=0){
//         int c = n%10;
//         sum = sum + c ;
//         n = n/10;
//     }
//     cout << sum;
// }
//6
// int main(){
//     long long n;
//     cin >> n;
//     while(n!=0){
//         int c = n%10;
//         if(c!=0){
//             cout << c;
//             n = n/10;
//         }
//         n = n/10;
//     }
// }

// int main(){
//     int n;
//     cin >> n;

//     for(long long i = 2 ; i * i <= n; i++){
//         if(n%i == 0){
//             cout << i << endl;
//             return 0;
//         }
//     }
//     cout << n ;
// }


// int main(){
//     long long n;
//     cin >> n;
//     int count = 0;
//     for(long long i = 1; i*i <= n;i++){
//         if(n%i == 0 ){
//             if(i*i == n) count++;
//             else count += 2;
//         };
//     }
//     cout << count;
// }


int main(){
    //int x;
    int n;
    cin >> n;
    long long sum = 0;
    for(long long i = 0 ; i < n ; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << sum;
    return 0;
}
 