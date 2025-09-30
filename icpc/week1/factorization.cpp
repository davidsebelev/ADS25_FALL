#include<iostream>
using namespace std;

int main(){
    int n;
    cin >>n;


    vector<pair<int,int> >  f;
    //int cnt= 0;
    
    for(int i = 2; i * i <= n; i++){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                n = n/i;
                cnt++;
            }
            f.push_back(make_pair(i,cnt));
        }
    }


    if(n > 1) f.push_back(make_pair(n, 1));
    //

    // for(int i = 0 ; i < f.size();i++){
    //     while(f[i].second--){
    //         cout << f[i].first << " ";
    //     }
    // }


    for(int i = 0 ; i < f.size();i++){
        cout << f[i].first;
        if(f[i].second > 1){
            cout << "^" << f[i].second;
        }
        if(i + 1 != f.size()) cout << "*";
    }
    return 0;
}