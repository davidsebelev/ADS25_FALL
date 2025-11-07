#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll pw1 = 31;
const ll pw2 = 37;

pair<vector<ll>, vector<ll>> prefix_hash(const string &s, ll mod, ll pw) {
    int n = s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + s[i]) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return {h, p};
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod) {
    return ((h[r] - h[l] * p[r - l]) % mod + mod) % mod;
}

string get_common_substring(vector<string> &arr, int len) {
    if (len == 0) return "";

    unordered_set<ull> common;
    bool first = true;

    for (const string &s : arr) {
        auto [h1, p1] = prefix_hash(s, mod1, pw1);
        auto [h2, p2] = prefix_hash(s, mod2, pw2);

        unordered_set<ull> current;

        for (int i = 0; i + len <= (int)s.size(); i++) { 
            ll hsh1 = get_hash(h1, p1, i, i + len, mod1);
            ll hsh2 = get_hash(h2, p2, i, i + len, mod2);
            ull h = (ull(hsh1) << 32) ^ ull(hsh2);
            current.insert(h);
        }

        if (first) {
            common = move(current);
            first = false;
        } else {
            unordered_set<ull> next;
            for (auto &h : current)
                if (common.count(h))
                    next.insert(h);
            common = move(next);
            if (common.empty()) return "";
        }
    }

    if (common.empty()) return "";

    auto [h1, p1] = prefix_hash(arr[0], mod1, pw1);
    auto [h2, p2] = prefix_hash(arr[0], mod2, pw2);
    for (int i = 0; i + len <= (int)arr[0].size(); i++) {
        ll hsh1 = get_hash(h1, p1, i, i + len, mod1);
        ll hsh2 = get_hash(h2, p2, i, i + len, mod2);
        ull h = (ull(hsh1) << 32) ^ ull(hsh2);
        if (common.count(h)) {
            return arr[0].substr(i, len);
        }
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    int l = 0;
    int r = INT_MAX;
    for (auto &s : a)
        r = min(r, (int)s.size());

    int ans_len = 0;
    string ans_str = "";

    while (l <= r) {
        int mid = (l + r) / 2;
        string res = get_common_substring(a, mid);
        if (!res.empty()) {
            ans_len = mid;
            ans_str = res;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans_str << "\n";
    return 0;
}
