#include<iostream>
#include<vector>
using namespace std;

int lr_bound(vector<int>& pref, int mistake){
    int l = -1;
    int r = pref.size();


    while(l + 1 < r){
        int mid = (l + r ) /2;
            if(pref[mid] < mistake){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r + 1;
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0 ; i  <  n ; i++) cin >> a[i];

    vector<int> pref(n);
    pref[0] = a[0];
    for(int i = 1 ; i  <  n ; i++){
        pref[i] = pref[i-1] + a[i];
    }
    // получили суммы например если а 5 7 6
    // то суммы 5 12 18
    while(m--){
    // int l = -1;
    // int r = pref.size();

    int mis;
    cin >> mis;

    cout << lr_bound(pref,mis) << endl;

    // while(l + 1 < r){
    //     int mid = (l + r ) /2;
    //         if(a[mid] <= mis){
    //             l = mid;
    //         }else{
    //             r = mid;
    //         }
    //     }
    // }
    }
    return 0;
}