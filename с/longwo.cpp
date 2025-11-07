#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        string w;
        cin  >> w;

        if(w.length() > 10){
            char f = w[0];
            char s = w[w.length()-1];
            
            int cnt = w.length()-2;
            cout << f << cnt << s << "\n";
        }else{cout << w <<"\n";}
    }
    return 0;
}