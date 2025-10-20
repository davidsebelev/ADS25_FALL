#include<bits/stdc++.h>
using namespace std;

struct gpa
{
    string name;
    string surname;
    double gp;

    gpa() = default;
    
    gpa(string n, string s, double g){
        name = n;
        surname = s;
        gp = g;
    }
};

bool comp(const gpa &a , const gpa &b){
    if(a.gp == b.gp){
        if(a.name == b.name){
            return a.surname < b.surname;
        }else{
            return a.name < b.name;
        }
    }else{
        return a.gp < b.gp;
    }
}

template<class T, class Compare>
void merge(vector<T> &a, int l , int m , int r,Compare comp){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<T> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++) L[i] = a[i+l];
    for(int j = 0 ; j < n2;j++) R[j] = a[j + m + 1];


    int uk1 = 0;
    int uk2 = 0;
    int k  = l;

    while(uk1 < n1 and uk2 < n2){
        if(comp(L[uk1],R[uk2])){
            a[k] = L[uk1];
            uk1++;
        }else{
            a[k] = R[uk2];
            uk2++;
        }
        k++;
    }

    while(uk1 < n1)a[k++] = L[uk1++];
    while(uk2 < n2)a[k++] = R[uk2++];
}

template<class T, class Compare>
void merge_sort(vector<T> &a, int l , int r,Compare comp){
    if(l>=r)return;
    int m = (l+r)/2;
    merge_sort(a,l,m,comp);
    merge_sort(a,m+1,r,comp);
    merge(a,l,m,r,comp);
}

int main(){
    int n;
    cin >> n;
    vector<gpa> v;
    while(n--){
        string name,s;
        int x;
        cin >> name >> s >> x;
        double g_ic = 0;
        double gpa = 0;
        double c_sum = 0;
        while(x--){
            string g;
            int c;
            cin >> g >> c;
            double g_i = 0;
            if(g == "A+"){
                g_i = 4.00;
            }else if(g == "A"){
                g_i = 3.75;
            }
            else if(g == "B+"){
                g_i = 3.5;
            }else if(g == "B"){
                g_i = 3.00;
            }else if(g == "C+"){
                g_i = 2.5;
            }else if(g == "C"){
                g_i = 2.00;
            }else if(g == "D+"){
                g_i = 1.5;
            }else if(g == "D"){
                g_i = 1.00;
            }else if(g == "F"){
                g_i = 0;
            }

            g_ic += g_i*c;
            c_sum += c;
        }
        gpa = g_ic/c_sum;

        v.emplace_back(name,s,gpa);
    }
    //sort(v.begin(),v.end(),comp);

    merge_sort(v,0,v.size()-1,comp);

    cout << fixed << setprecision(3);
    for(auto x : v){
        cout << x.name << " " << x.surname << " " << x.gp << "\n";
    }

    return 0;
}