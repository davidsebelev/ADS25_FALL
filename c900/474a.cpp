#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> keys = {
    'q','w','e','r','t','y','u','i','o','p',
    'a','s','d','f','g','h','j','k','l',';',
    'z','x','c','v','b','n','m',',','.','/'
};

    char s;
    cin >> s;

    if(s == 'R'){
        string word;
        cin >> word;
        for(int i = 0 ; i < word.size();i++){
            for(int j  = 0; j < keys.size();j++){
                if(word[i] == keys[j]){
                    cout << keys[j-1];
                }
            }
        }
    }else{
        string word;
        cin >> word;
        for(int i = 0 ; i < word.size();i++){
            for(int j  = 0; j < keys.size();j++){
                if(word[i] == keys[j]){
                    cout << keys[j+1];
                }
            }
        }
    }


    
    return 0;
}