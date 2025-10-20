#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l +1;
    int n2 = r - m;

    vector<int> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2; j++) R[j] = a[m + j + 1];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while(uk1 < n1 and uk2 < n2){
        if(L[uk1] <= R[uk2]){
            a[k] = L[uk1];
            uk1++;
        }else{
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while(uk1 < n1){
        a[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2 < n2){
        a[k] = R[uk2];
        uk2++;
        k++;
    }
}

void merge_sort(vector<int> &a, int l, int r){
    if(l >= r)return;
    int m = (l + r)/2;

    merge_sort(a,l,m);
    merge_sort(a,m+1,r);

    merge(a,l,m,r);
}

int bin_s(vector<int> &a, int x){
    int l = 0;
    int r = a.size()-1;

    while( l <= r){
        int m = (l+r)/2;
        if(a[m] == x) return m; // return ind el
        else if(a[m] < x)l = m+1;
        else r = m-1;
    }
    return -1; 
}


int main(){
    int n,m;
    cin >> n >> m;

    vector<int> a(n),b(m),r;


    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];

    merge_sort(a,0,a.size()-1);
    merge_sort(b,0,b.size()-1);

    if(n >m){
       for(int i = 0 ; i < n ;i++){
        for(int j = 0; j < m ; j++){
            if(a[i] == b[j]){
                r.push_back(a[i]);
                a[i] = INT_MAX;
                b[j] = INT_MIN;
            }
        }
    }
    }else{
        for(int i = 0 ; i < m ;i++){
        for(int j = 0; j < n ; j++){
            if(b[i] == a[j]){
                r.push_back(b[i]);
                b[i] = INT_MAX;
                a[j] = INT_MIN;
            }
        }
    }
    }

    for(int i = 0 ; i < r.size() ; i++) cout << r[i] << " ";
    


    return 0;

}