#include<iostream>
#include<vector>
using namespace std;

int bin_search(vector<int> &row, int x, bool increase){
    int l = 0;
    int r = row.size() - 1;

    while(l <= r ){
        int m = (l + r) / 2;

        if(row[m] == x) return m;


        if(increase){
            if(row[m] < x){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }else{
            if(row[m] < x){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    vector<int> q(t);
    for(int i = 0 ; i < t ; i++) cin >> q[i];


    int n,m;
    cin >> n >> m;

    vector<vector <int> > a(n,vector<int>(m));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++ ) cin >> a[i][j];
    }


    for(int x = 0 ; x < q.size();x++)
    {   
        bool found = false;
        for(int i = 0 ; i < n && !false ; i++){
            int j = bin_search(a[i], q[x],i%2 == 1);
            if(j != -1){
                cout << i << " " << j << "\n";
                found = true;
            }
        }
        if(!found) cout << -1 << "\n";
    }



}