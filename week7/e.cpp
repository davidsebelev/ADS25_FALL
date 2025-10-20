#include<bits/stdc++.h>
using namespace std;



bool comp(const vector<int> &x, const vector<int> &y){
    int sumX = 0;
    int sumY = 0;
    int m = x.size();

    for (int i = 0; i < m; i++) sumX += x[i];
    for (int i = 0; i < m; i++) sumY += y[i];

    if(sumX == sumY){
        for(int i = 0 ; i < m ; i++){
            if(x[i] != y[i]){
                return x[i] < y[i];
            }else{
                return false;
            }
        }
    }else{
        return sumX > sumY;
    }
}


template < class T , class Compare>
void merge(vector<T> &a, int l, int m, int r,Compare comp){
    int n1 = m - l +1;
    int n2 = r - m;

    vector<T> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++) L[i] = a[l+i];
    for(int j = 0 ; j < n2; j++) R[j] = a[m + j + 1];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while(uk1 < n1 and uk2 < n2){
        if(comp(R[uk2],L[uk1])){
            a[k++] = R[uk2++];
        }else{
            a[k++] = L[uk1++];
        }
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

template<class T, class Compare>
void merge_sort(vector<T> &a, int l, int r,Compare comp){
    if(l >= r)return;
    int m = (l + r)/2;

    merge_sort(a,l,m,comp);
    merge_sort(a,m+1,r,comp);

    merge(a,l,m,r,comp);
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> > a(n,vector<int> (m));
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j  < m ; j++){
            cin >> a[i][j];
        }
    }

    merge_sort(a,0,a.size()-1,comp);


   for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j  < m ; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}