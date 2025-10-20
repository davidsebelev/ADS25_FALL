#include<bits/stdc++.h>
using namespace std;

void QuickSort(vector<int> &a, int l, int r){
    if (l >= r) return;                  

    int i = l, j = r;
    int p = a[l + (r - l) / 2];            

    while (i <= j) {                      
        while (i <= r && a[i] < p) i++;    
        while (j >= l && a[j] > p) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }

    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}


int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
    };


    //for(int i = 0 ; i < n ;i++){a[i] = abs(a[i]);};

    QuickSort(a,0,a.size()-1);


     vector<pair<int,pair<int,int> > > d;

    for(int i = 1 ;i < n ; i++){
        int dif = abs(a[i] - a[i-1]);
        d.push_back(make_pair(a[i-1], make_pair(a[i], dif)));
    }




     vector<pair<int,int> > r;


    int min_dif = d[0].second.second;
    for(vector<pair<int,pair<int,int> > >::iterator it = d.begin();it!= d.end();it++){
         min_dif = min(min_dif,it->second.second);
    }

    for(vector<pair<int,pair<int,int> > >::iterator it = d.begin();it!= d.end();it++){
         if(min_dif == it->second.second)r.push_back(make_pair(it->first,it->second.first));
    }




    for(vector<pair<int,int> >::iterator it = r.begin();it!= r.end();it++){
        cout << it->first << " " << it->second << " ";
    }
    

    return 0;
}