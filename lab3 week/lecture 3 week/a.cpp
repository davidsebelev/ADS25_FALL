#include<iostream>
#include<vector>
using namespace std;

int bin_search(const vector<int>& row, int x,bool decreasing){
    int l = 0 , r = row.size() - 1;

    while(l <= r){
        int mid = (l+r)/2;
        if(row[mid] == x) return mid;
        if(!decreasing){
            if(row[mid] < x) l = mid + 1;
            else r = mid - 1;
        }else{
            if(row[mid] > x) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    vector<int> queries(t);
    for (int i = 0; i < t; i++) cin >> queries[i];

    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    for (int q : queries) {
        bool found = false;
        for (int i = 0; i < n && !found; i++) {

            int left = mat[i][0], right = mat[i][m - 1];
            if (left > right) swap(left, right);

            if (q < left || q > right) continue; 

            int pos = bin_search(mat[i], q, mat[i][0] > mat[i][m - 1]);
            if (pos != -1) {
                cout << i << " " << pos << "\n";
                found = true;
            }
        }
        if (!found) cout << -1 << "\n";
    }
    
    return 0;
}