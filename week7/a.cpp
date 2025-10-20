#include<bits/stdc++.h>
using namespace std;

bool comp (const string &a,const  string &b){

        return a.length() < b.length();
    //return a.length() < b.length();
}



template<class T, class Compare>
void merge(vector<T> &words, int l, int m, int r,Compare comp){
    int n1 = m - l +1;
    int n2 = r - m;

    vector<T> L(n1),R(n2);

    for(int i = 0 ; i < n1 ; i++) L[i] = words[l+i];
    for(int j = 0 ; j < n2; j++) R[j] = words[m + j + 1];

    int uk1 = 0;
    int uk2 = 0;
    int k = l;

    while(uk1 < n1 and uk2 < n2){
        if(comp(R[uk2],L[uk1])){
            words[k++] = R[uk2++];
        }else{
            words[k++] = L[uk1++];
        }
    }

    while(uk1 < n1){
        words[k] = L[uk1];
        uk1++;
        k++;
    }
    while(uk2 < n2){
        words[k] = R[uk2];
        uk2++;
        k++;
    }
}
template<class T, class Compare>
void merge_sort(vector<T> &words, int l, int r,Compare comp){
    if(l >= r)return;
    int m = (l + r)/2;

    merge_sort(words,l,m,comp);
    merge_sort(words,m+1,r,comp);

    merge(words,l,m,r,comp);
}

int main(){
    int n;
    cin >> n;
    cin.ignore(); 
    while(n--){
        string line;
        getline(cin,line);
        stringstream ss(line);

        bool ok = true;
        int first_len = -1;
        vector<string> words;

        string word;
        while(ss >> word){  
            if(first_len == -1){
                first_len = word.length();
            }else{
                if(first_len != word.length()){
                    ok  = false;
                }
            }
            words.push_back(word);
        }

        if(!ok){
            merge_sort(words,0,words.size()-1,comp);
        }

        for(int i = 0; i < words.size();i++) cout << words[i] << " ";
        cout << "\n";
    }
    return 0;
}