#include<bits/stdc++.h>
using namespace std;


void quick_sort(vector<char> &a,int l,int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];


    while(i  < j){
        while(a[i] < p)i++;
        while(a[j] > p)j--;

        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l <  j) quick_sort(a,l,j);
    if(i < r)quick_sort(a,i,r);
}



int main(){
    int n;
    cin >> n;

    vector<char> a(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];

    char ch;
    cin >> ch;

    quick_sort(a,0,a.size()- 1);
    bool fl = false;
    for(int i = 0 ; i < n; i++){
        if(ch < a[i]){
            cout << a[i];
            fl = true;
            break;
        }
    }


    if(!fl){
        cout << a[0];
    }
    //queue<char> q;
    // for(int i = 0 ; i < a.size();i++){
    //     q.push(a[i]);
    // }
    // bool fl = false;
    // while(!q.empty() && !fl){
    //     if(ch[i])
    // }

    return 0;
}