#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    int r = (n * 100 + m) * k;
    cout << r /100 << " " << r%100;
    return 0;
}