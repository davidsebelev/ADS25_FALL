#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //
   //Дана строка. Требуется определить, какой символ встречается в ней чаще всего.
   string s;
   cin >> s;

   map<char,int> m;

   for(int i  = 0 ; i < s.size();i++){
        m[s[i]]++;
   }

   for(auto i : s)cout << i << " ";
   cout << "\n";
   for(auto i : m)cout << i.first << " " << i.second << "\n";
    
    return 0;
}