#include<bits/stdc++.h>
using namespace std;

template <class T>

int b_find(vector<T>& a, const T& x){
    int l = 0;
    int r = a.size()-1;

    while(l <= r){
        int m = (l+r)/2;

        if(a[m] == x){
            if(a[m] == INT_MAX)return -1;
            else return m;
            }

        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
template <class T>
void quick_sort(vector<T>& a, int l , int r){
    int i = l;
    int j = r;
    int p = a[(l+r)/2];

    while(i < j){
        while(a[i] < p)i++;
        while(a[j] > p)j--;

        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }

    if(l < j)quick_sort(a,l,j);
    if(i < r)quick_sort(a,i,r);
}




int main(){
    int n,m;
    cin >> n >> m;

    vector<int> f(n);
    vector<int> s(m);

    for(int i = 0 ; i < n ; i++) cin >> f[i];
    for(int i = 0 ; i < m ; i++) cin  >> s[i];

    quick_sort(f,0,f.size()-1);
    quick_sort(s,0,s.size()-1);

    // for(int i = 0 ; i < n ;i++) cout << f[i] << " ";
    // cout << "\n";
    // for(int i = 0 ; i< m ;i++) cout << s[i] << " ";
    // cout << "\n";
    vector<bool> used(m, false);
    vector<int> r;
    if(n > m){
        for(int i = 0; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                
            }
            break;
        }
    }else{
        for(int i = 0; i < m ;i++){ // 5
            for(int j = 0 ; j < n ;j++){ // 3
                if(b_find(s,f[j])){r.push_back(f[j]);};
            }
            break;
        }
    }

    for(int i = 0 ;i < r.size();i++) cout << r[i] << " ";


    return 0;
}