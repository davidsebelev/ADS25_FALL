#include<bits/stdc++.h>
using namespace std;

template<class T>
void quick_sort(vector<T> &b, int l , int r){
    int i = l;
    int j = r;
    T p = b[(l+r)/2];

    while(i < j){
        while(b[i] < p)i++;
        while(b[j] > p)j--;

        if(i<=j){
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    if(l < j)quick_sort(b,l,j);
    if(i < r)quick_sort(b,i,r);
}


int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int> > a(n,vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int> > b(m,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            b[j][i] = a[i][j];
        }
    }

    //quick_sort(b,0,b.size()-1);

    for (int i = 0; i < m; i++)
        quick_sort(b[i], 0, n - 1);

    for(int i = 0 ; i < m ; i++){
        reverse(b[i].begin(),b[i].end());
    }

   vector<vector<int> > c(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
                c[i][j] = b[j][i];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
                cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}