#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> num;

        string n_n = to_string(n);
        int size_n = n_n.size();



        int save = n;

        int d = 1;

        for(int i = 0 ; i  < size_n - 1 ; i++){
            d = d*10;
        }

        int r = n%d;

        int prim = n;//9870
        int prim2 = n - r;//9000

        int q = 10;
        while(n != prim2){
            int rr = n%q;
            n = n - rr;
             if(rr!=0)num.push_back(rr);

            if(n==prim2)break;
            q = q*10;

        }
        sort(num.begin(),num.end());
        num.push_back(prim2);

        cout <<num.size() << "\n";

        for(int i = 0 ; i < num.size() ; i++)cout << num[i] << " ";
        cout << "\n";
    }
    
    return 0;
}