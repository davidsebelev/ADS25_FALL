#include<bits/stdc++.h>
using namespace std;

struct dates{
    int day;
    int month;
    int year;
    string date;


    dates(int d, int m, int y, string dt) {
        day = d;
        month = m;
        year = y;
        date = dt;
    }
};
bool comp(const dates &a, const dates &b){
    if(a.year == b.year){
        if(a.month == b.month){
            return a.day < b.day;
        }else{
            return a.month < b.month;
        }
    }else{
        return a.year < b.year;
    }
}
template<class T, class Compare>
void quick_sort(vector<T> &a,int l,int r, Compare comp){
    int i = l;
    int j = r;
    T p = a[(l+r)/2];

    while(i < j){
        while(comp(a[i], p))i++;
        while(comp(p,a[j]))j--;

        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l < j) quick_sort(a,l,j,comp);
    if(i < r) quick_sort(a,i,r,comp);
}

int main(){
    int n;
    cin >> n;

    vector<dates> d;
    while(n--){
        string word;
        cin >> word;

        string date = "";
        //for(int i = 0 ; i < word.length();i++){
            //day = s[0]+s[1]
            //month = s[3]+s[4]
            //year = s[6]+s[7]+s[8]+s[9]
            string datD = word.substr(0, 2);
            int day  = stoi(datD); // for sort

            string datM = word.substr(3,2);
            int month = stoi(datM);

            string datY = word.substr(6,4);
            int year = stoi(datY);

            d.emplace_back(day,month,year,word);

            //cout << day << " " << month << " " << year;
            
            // int temp = stoi(date);
            //d.push_back({date});
    }
    quick_sort(d,0,d.size()-1,comp);

    for (auto &x : d) {
        cout << x.date << "\n";
    }
    return 0;

}