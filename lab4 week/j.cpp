#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void buildBalanced(vector<int>& arr, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;           // середина
    result.push_back(arr[mid]);      // сначала кладём середину (корень)
    buildBalanced(arr, l, mid - 1);  // рекурсивно левая половина
    buildBalanced(arr, mid + 1, r);  // рекурсивно правая половина
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int size = (1 << N) - 1; // 2^N - 1
    vector<int> arr(size);
    for (int i = 0; i < size; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());  // сортируем, чтобы работал BST
    buildBalanced(arr, 0, size - 1);

    for (int x : result) cout << x << " ";
    cout << "\n";
}