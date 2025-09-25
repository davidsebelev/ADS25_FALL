#include<iostream>
#include<vector>
using namespace std;



// pair<int,int> checkPower(vector<int>& a, int power){
//     int cnt = 0, sum = 0;
//     for(int i = 0 ; i < a.size();i++){
//         if(power == max(a[i],power)){
//             sum+=a[i];
//             cnt++;
//         }
//     }
//     return make_pair(cnt,sum);
// }

vector<int> pref_sum(vector<int>& a){
    vector<int> p(a.size());
    p[0] = a[0];
    for(int i = 1 ; i < a.size() ;i++){
        p[i] = p[i - 1] + a[i];
    }
    return p;
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a.begin(),a.end());

    int p;
    cin >> p;


    // pair<int, int> r = checkPower(a,p);
    // int cnt = r.first;  // первый элемент пары
    // int sum = r.second;
    // cout << cnt << " " << sum;
    while(p--){
        int l = -1;
        int r = n;

        int powr;
        cin >> powr;
        while(l + 1 < r){
            int m = (l  + r) /2;
            if(a[m] <= powr){
                l = m;
            }else{
                r = m;
            }
        }
        vector<int> p = pref_sum(a);
        // cout << l  + 1<< endl;
        // for(int i = 0 ; i < n ; i++){
        //     cout << p[i] << " ";
        // }
        cout << l + 1 << " " << p[l] << endl;
    }


    return 0;
}