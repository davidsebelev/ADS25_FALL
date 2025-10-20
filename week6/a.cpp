#include<bits/stdc++.h>
using namespace std;

// разделяешь строку относительно пивот буквы
// 
bool isVowel(char c){
    return (c == 'a' or c == 'o' or c == 'i' or c == 'e' or c == 'u');
}

bool compare(char a, char b){
    bool ok1 = isVowel(a);
    bool ok2 = isVowel(b);

    if(ok1 != ok2) return ok1;
    return a < b;
}



void QuickSort(string &s,int l, int r){
    int i = l;
    int j = r;
    int p = (s[(l+r)/2]);

    while(i < j){
        while(compare(s[i],p))i++;
        while(compare(p,s[j]))j--;


        if(i <= j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    if(l < j) QuickSort(s,l,j);
    if(i < r) QuickSort(s,i,r);
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    QuickSort(s,0,n-1);
    cout << s << "\n";
    return 0;
}