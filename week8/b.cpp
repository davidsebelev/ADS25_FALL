#include<bits/stdc++.h>
using namespace std;


//for pattern hashing string t for ex
int get_h(string s){
    int h = 0;
    int p = 31;
    int p_pow = 1;

    for(int i = 0; i < s.size();i++){
        h += s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}

//making arr of prefix hashs
vector<int> arr_h(string s){
    int n =s.size();
    vector<int> h(n);

    int p_pow = 31;
    int p = 31;

    h[0] = s[0];
    for(int i = 1 ; i < n ;i++){
        h[i] = h[i-1] + s[i]*p_pow;
        p_pow*=p;
    }
    return h;
}



// disticnt substrings 
//abc 
// a ab abc

int main(){
    string s,ss,t;
    cin >> s >> ss >> t;


    int n = s.size();//first words size
    int m = t.size();//parasit size

    int z = ss.size();//second word size

    int h_t = get_h(t);//hash pattern

    //size hash vector first and second word
    vector<int> h = arr_h(s);
    vector<int> h2 = arr_h(ss);


    vector<int> p(max(n,z));
    p[0] = 1;
    for(int i = 1 ; i < (int)p.size() ; i++)p[i] = p[i-1]*31;

    //result vetors first occurence of pattern
    vector<int> b;
    vector<int> f;


    for(int i = 0 ; i < n - m + 1;i++){
        int j = i + m  - 1;
        int h_t_j = h[j];

        if(i > 0)h_t_j -=h[i-1];
        if(h_t_j == h_t*p[i])b.push_back(i);

    }


    for(int i = 0 ; i < z - m + 1;i++){
        int j = i + m  - 1;
        int h_t_j = h2[j];

        if(i > 0)h_t_j -=h2[i-1];
        if(h_t_j == h_t*p[i])f.push_back(i);

    }
    vector<int> rrr;



    
    for(int i = 0 ; i < b.size();i++)rrr.push_back(b[i]);
    for(int i = 0 ; i < f.size();i++)rrr.push_back(f[i]);

     sort(rrr.begin(),rrr.end());

    int cnt = 0;
    for(int i = 1; i < rrr.size() ;i++){
        if(rrr[i-1] == rrr[i])cnt++;
    }
    cout << cnt;

// 0 4 8 8 if a[i-1] == a[i]
    
    
    return 0;   
}