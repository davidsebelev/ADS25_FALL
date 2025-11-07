#include<bits/stdc++.h>
using namespace std;

void table(int x){for(int i = 0 ; i <= 10 ;i++)cout << x << " * " << i << " = " << x*i << "\n";}

void recTable(int x,int i = 1){
    if(i == 11)return;

    cout << x << " * " << i << " = " << x*i << "\n";
    i++;
    recTable(x,i);
}

int main(){
    int n;
    cin >> n;

    table(n);
    
    cout << "\n";

    recTable(n);
    return 0;
}