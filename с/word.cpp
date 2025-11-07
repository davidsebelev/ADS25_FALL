#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;

    int cntU = 0;
    int cntL = 0;

    for(int i = 0 ; i < s.size();i++){
        if(isupper(s[i]))cntU++;
        else cntL++;;
    }


    for(int i = 0 ; i < s.size();i++){
        if(cntU > cntL){s[i]=toupper(s[i]);}
        else if(cntU == cntL){s[i] = tolower(s[i]);}
        else {s[i] = tolower(s[i]);}
    }

    cout << s;
    return 0;
}