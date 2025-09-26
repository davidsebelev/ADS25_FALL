#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> el(t);
    for(int i = 0; i < t ; i++) cin >> el[i];

    int n, m;
    cin >> n >> m;


    map<int, pair<int,int> > mp; 
    map<int,int> ok;
    int a[n][m];
    for(int x = 0; x < n ; x++){
        for(int y = 0 ; y < m; y++){
            int v;
            cin >> v;
            mp[v] = make_pair(x,y);
            ok[v] = 1;
        }
    }


   

    

//     for(map<int, pair<int,int>>::iterator it = mp.begin(); it != mp.end(); it++){
//     cout << it->first << " " << it->second.first << " " << it->second.second << endl;
// }


    for(int z = 0 ; z < t ; z++){
        if(ok[el[z]] == 1) cout << mp[el[z]].first << " " << mp[el[z]].second << endl;
        else cout << -1 << endl;
    }

    return 0;    


}