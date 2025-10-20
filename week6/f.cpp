#include<bits/stdc++.h>
using namespace std;


bool compare_gpa(const pair<string,pair<string,double> >  &a,const pair<string,pair<string,double> >  &b){
    if(a.second.second == b.second.second){
        if(a.first == b.first){
            return a.second.first < b.second.first;
        }else{
            return a.first < b.first;
        }
    }else{
        return a.second.second < b.second.second;
    }
}

template <class T, class Compare>
void quick_sort(vector<T>& a, int l, int r, Compare comp) {
    int i = l;
    int j = r;
    T pivot = a[(l + r) / 2];

    while (i <= j) {
        while (comp(a[i], pivot)) i++;
        while (comp(pivot, a[j])) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quick_sort(a, l, j, comp);
    if (i < r) quick_sort(a, i, r, comp);
}


int main(){
    int n;
    cin >> n;
    // double res = 0;
    // double cre_res = 0;
    vector<pair<string,pair<string,double> > > re;
    vector<double> gpa_r;
    while(n--){
        string name,surname;
        int q;
        cin >> name >> surname >> q;

        double res = 0;
        double cre_res = 0;
        while(q--){
            string gpa;
            int credit;
            cin >> gpa >> credit;
            vector<double> gp;
            // double res = 0;
            // double cre_res = 0;
            if(gpa == "A+"){
                gp.push_back(4.00);
                res += 4.00 * credit;
                cre_res+=credit;
            }else if(gpa == "A"){
                gp.push_back(3.75);
                res += 3.75 * credit;
                cre_res+=credit;
            }else if(gpa == "B+"){
                gp.push_back(3.5);
                res += 3.5 * credit;
                cre_res+=credit;
            }else if(gpa == "B"){
                gp.push_back(3.00);
                res += 3.00 * credit;
                cre_res+=credit;
            }else if(gpa == "C+"){
                gp.push_back(2.5);
                res += 2.5 * credit;
                cre_res+=credit;
            }else if(gpa == "C"){
                gp.push_back(2.00);
                res += 2.00 * credit;
                cre_res+=credit;
            }else if(gpa == "D+"){
                gp.push_back(1.5);
                res += 1.5 * credit;
                cre_res+=credit;
            }else if(gpa == "D"){
                gp.push_back(1.00);
                res += 1.00 * credit;
                cre_res+=credit;
            }else if(gpa == "F"){
                gp.push_back(0.00);
                res += 0.00 * credit;
                cre_res+=credit;
            }
        }

            re.push_back(make_pair(name,make_pair(surname,res/cre_res)));
    
        //gpa_r.push_back(res/cre_res);
    }
    quick_sort(re,0,re.size()-1,compare_gpa);
    cout << fixed << setprecision(3) << showpoint;
    for(vector<pair<string,pair<string,double> > >::iterator it = re.begin();it!= re.end();it++){
            cout << it->first << " " << it->second.first << " " << it->second.second <<  "\n";
    }

    // for(int i = 0 ; i < gpa_r.size();i++) cout << gpa_r[i] << " ";
    // for(vector<pair<string,pair<string,double> > >::iterator it = re.begin();it!= re.end();it++){

    // }

    // cout << res << "\n";
    // cout << cre_res << "\n";
    return 0;
}