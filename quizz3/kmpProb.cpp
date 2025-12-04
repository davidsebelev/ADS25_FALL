#include <bits/stdc++.h>
using namespace std;

int count_occurrences(string text, string pattern) {
    string s = pattern + "#" + text;
    vector<int> pi = prefix_function(s);
    int m = pattern.size();
    int count = 0;

    for (int i = m + 1; i < s.size(); i++) {
        if (pi[i] == m) {
            count++;
        }
    }

    return count;
}

vector<int> find_all_borders(string s) {
    int n = s.size();
    vector<int> pi = prefix_function(s);
    vector<int> borders;

    int k = pi[n - 1];
    while (k > 0) {
        borders.push_back(k);
        k = pi[k - 1];
    }

    reverse(borders.begin(), borders.end());
    return borders;
} // тип находит граниы где префискс равен суффиксу 

// Example: s = "abcabcab"
// Borders: lengths 2, 5 ("ab", "abcab")

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}