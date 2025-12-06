#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> d(n);
    for (auto &x : d) cin >> x;

    vector<long long> key(n, LLONG_MAX);
    vector<int> used(n, 0);

    key[0] = 0; 
    long long mst_cost = 0;

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || key[j] < key[v]))
                v = j;
        }

        used[v] = 1;
        mst_cost += key[v];

        for (int u = 0; u < n; u++) {
            if (!used[u]) {
                long long w = d[v] + d[u];
                if (w < key[u]) key[u] = w;
            }
        }
    }

    cout << mst_cost;
}