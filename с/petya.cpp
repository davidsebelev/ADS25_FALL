#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    string w1 = "";
    string w2 = "";
    for(int i = 0 ; i < a.size();i++){
        w1+=tolower(a[i]);
    }

    //cout << w1;
    for(int i = 0 ; i < b.size();i++){
        w2+=tolower(b[i]);
    }
    //cout << endl;

    //cout << w2;

        int cnt = 0;
        for(int i = 0 ; i < w1.length();i++){
            if(w1[i]!=w2[i]){
                if(w1[i] < w2[i]){
                    cout << -1;
                }else{
                    cout << 1;
                }
                return 0;
            }else {
                cnt++;
            }
        }

        if(cnt == w1.size())cout << 0;


    // int size1 = 0;
    // int size2 = 0;
    // for(int i = 0 ; i < w1.size();i++){
    //     size1+=(int)w1[i];
    // }
    // for(int i = 0 ; i < w2.size();i++){
    //     size2+=(int)w2[i];
    // }
    // cout << size1 << " " << size2 << endl;

    // if(size1 < size2)cout << -1;
    // else if(size2 < size1) cout << 1;
    // else cout << 0;
}