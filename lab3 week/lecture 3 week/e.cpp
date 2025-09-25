#include<iostream>
#include<vector>
using namespace std;

//long long r = 1;

bool good(vector<pair<int, int> >& a, int m ,int k){
    int cnt = 0;
    for(vector<pair<int,int> >::iterator it = a.begin(); it!= a.end();it++){
        int x2 = it->first;
        int y2  = it->second;
        if(x2 <= m && y2 <= m) cnt++;
    }
    return cnt >=k;
}


// int countCov(vector<pair<int, int> >& a, long long side){
//     int cnt = 0;
//     for(vector<pair<int,int> >::iterator it = a.begin(); it!= a.end();it++){
//         int x2 = it->first;
//         int y2  = it->second;
//         if(x2 <= m && y2 <= m) cnt++;
//     }
//     return cnt;
// }






int main(){
   int n, k ;
   cin >> n >> k;


   vector<pair<int,int> > a;
   for(int i = 0 ; i < n ; i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a.push_back(make_pair(x2,y2));
   }

  

     long long l = 0;
     long long r = 1e9;

     while(l + 1 < r){
        long long m = (l + r) / 2;
        if(good(a,m,k)){
            r = m;
        }else{
            l = m;
        }
     }
   
    cout << r;
   //cout << countCov(a,r) << endl;

    return 0;
}