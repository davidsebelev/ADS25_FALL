#include<iostream>
#include<queue>
using namespace std;


int main(){
    int n;
    string s;
    cin >> n >> s;
    

    queue<int> k;
    queue<int> sa;
    // заполняем индексами наши две очереди 
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'S'){
            sa.push(i);
        }else if (s[i] == 'K'){
            k.push(i);
        }
    }

    while(!sa.empty() && !k.empty()){
        int i = sa.front();
        int j = k.front();

        if(i < j){
            sa.pop();
            sa.push(i+n);
            k.pop();
        }else{
            k.pop();
            k.push(j+n);
            sa.pop();
        }
    }

    if (sa.empty()) cout << "KATSURAGI\n";
else cout << "SAKAYANAGI\n";







    

    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }


    
}