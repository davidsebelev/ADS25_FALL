#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int> &a, int k, long long X) {
    ll sum = 0;
    int cnt = 1; // минимум один участок

    for (int i = 0; i < a.size(); i++) {
        if (a[i] > X) return false; // один дом больше X — невозможно

        if (sum + a[i] <= X)
            sum += a[i]; // добавляем в текущий блок
        else {
            cnt++;       // начинаем новый блок
            sum = a[i];
        }
    }
    return cnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = -1;
    ll r = 1e9;

    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (check(a, k, m))
            r = m; // можно — пробуем меньше
        else
            l = m; // нельзя — увеличиваем X
    }

    cout << r;
    return 0;
}
