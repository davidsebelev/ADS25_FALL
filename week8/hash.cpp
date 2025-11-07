#include<bits/stdc++.h>
using namespace std;


//aabbcabc
// a a b b a b c
// h = a * 1
// p_pow = 31
int get_hash(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;
    for(int i = 0 ; i < s.size() ; i++){
        h+= s[i] * p_pow;
        p_pow *=p;
    }
    return h;
}


// int get_hashhh(string s){
//     int h = 0;
//     int p = 31;
//     int p_pow = 1;
//     for(int i = 0;  i < s.size();i++){
//         h += s[i]*p_pow;
//         p_pow *= p;
//     }
//     return h;
// }

//хэш для одной строки 
// int get_hashh(string s){
//     int h = 0;
//     int p = 31;
//     int p_pow = 1;
//     for(int i = 0 ; i < s.size();i++){
//         h+=s[i]*p_pow;
//         p_pow*=p;
//     }
//     return h;
// }

// arr prefix hash
vector<int> get_h(string s){
    int n = s.size();
    vector<int> h(n);

    h[0]=s[0];

    int p = 31;
    int p_pow = 31;

    for(int i = 1 ;i < n;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}


vector<int> get_hh(string s){
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 31;
    int p_pow = 31;

    for(int i = 1 ; i < n ;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;

}

//n = 8;
// m = 3;
// n - m + 1 = 6
// получается n - m + 1 это количество окон длинной m в нашем случае
//количество окон длинной 3


// j = i + m - 1;
// правый конец подстроки 
//например строка  aabbcabc
// таким образом если i = 2 and m = 3 
// j = i + m - 1 = 2 + 3 -1 = 4
// s равно подстрока [2;4] в нашем случае bbc


// h_i_j = h[j]
// if(i > 0) = h_i_j = h[j] - h[i-1];
//крч эо формула подстроки хэширования

//s = abcd
// i = 1 j == 3
//h_i_j = hash(abcd) - hash(a) = bcd hash


int main(){
    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    int h_t = get_hash(t);
    vector<int> h = get_h(s);
    vector<int> p(n);
    p[0] = 1;
    for(int i = 1 ;i < n ;i++){
        p[i] = p[i-1] * 31;
    }
    // cout << h_t << endl;
    // for(int i = 0 ; i < m ;i++)cout << h[i] << " ";


    for(int i =  0; i < n - m + 1;i++){
        int j = i + m - 1;
        int h_i_j = h[j];
        if(i > 0){
            h_i_j-=h[i-1];
        }
        if(h_i_j == h_t*p[i]){
            cout << i << " ";
        }
    }
    return 0;
}

//количество разных подстрок вывести число 
// например abc 
// a
// ab 
// abc 
// то есть три различных подстроки