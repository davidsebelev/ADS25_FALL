#include <bits/stdc++.h>
using namespace std;

vector<int> pref(string s){
    int n = s.size();
    vector<int> p(n);

    p[0] = 1;
    for(int i = 1 ; i < n ; i++){
        int j = p[i-1]; // длинна самого длинного префикса который равен суффиксу
        while(j > 0 && s[i]!=s[j]){
            j = p[j-1];  // отступаем типо назад чтобы найти длинный преф == суфф
        }

        if(s[i] == s[j])j++;
        p[i] = j;
    }
    return p;
}

void kmp(string text,string pattern){
    string s = pattern + "#" + text;

    int n = s.size();
    int m = pattern.size();

    vector<int> p = pref(s);
    // индексы:   0 1 2 ... m-1  m   m+1  m+2 ...
    // строка:   [pattern] '#' [----- text -----]


    for(int i = m + 1; i < n;i++){
        if(p[i] == m){
            // конец совпадения == i длинна его m i - m +1 
            // но так это в строке s следовательно нам нужно в text
            // поэтому text начинается с m + 1 поэётому 
            // pos = i - m + 1 - m - 1 == i-2m;
            int pos = i - 2*m;
            cout << pos << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    
    return 0;
}