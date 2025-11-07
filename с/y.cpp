#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;

    n = n + 1;

    bool fl = true;
    while(fl){
        string y = to_string(n);
        set<char> s;
        for(auto c : y){
        s.insert(c);
        }

        if(s.size() == y.size()){
            fl = false;
        }else{
            n +=1;
        }
    }

    cout << n;
    return 0;
}