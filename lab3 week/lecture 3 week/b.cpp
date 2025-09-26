#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long> a;

bool can(long long mid) {
    long long sum = 0;
    int parts = 1; // начинаем с первого блока
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) return false; // элемент сам больше mid
        if (sum + a[i] > mid) {
            parts++;        // начинаем новый блок
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return parts <= m;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = *max_element(a.begin(), a.end()); // минимум
    long long r = 0;
    for (auto x : a) r += x; // максимум
    long long ans = r;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
