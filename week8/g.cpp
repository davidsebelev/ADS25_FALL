#include<bits/stdc++.h>
using namespace std;


int get_h(string s){
    int h= 0;
    int p = 29;
    int p_pow= 1;

    for(int i = 0 ; i < s.size();i++){
        h+= s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

vector<int> arr_h (string s){
    int n = s.size();
    vector<int> h(n);

    h[0]=s[0];
    int p = 29;
    int p_pow = 29;

    for(int i = 1; i < n;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow *= p;
    }
    return h;
}


int main(){
    string s;
    cin >> s;

    int q;
    cin >> q;
    int n = s.size();

    vector<int> p(n);
    p[0] = 1;
    for(int i = 1;  i < n;i++){
        p[i] = p[i-1]*29;
    }


    vector<int> h = arr_h(s);
    while(q--){
        int a,b;//границы
        cin >> a >> b;

        string pattern = "";
        for(int i = a-1 ; i <= b-1;i++){
            pattern +=s[i];
        }

        int h_t = get_h(pattern);

        int m = pattern.size();

        int cnt = 0;


        for(int i = 0;  i < n - m + 1 ; i++){
            int j = i + m - 1;
            int h_t_j = h[j];

            if(i > 0)h_t_j -= h[i-1];
            if(h_t_j == h_t*p[i])cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}