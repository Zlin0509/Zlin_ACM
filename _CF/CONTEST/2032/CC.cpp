#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
map<int, int> cnt;

inline void Zlin() {
    cin >> n;
    vi a(n);
    cnt.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // Sort and remove duplicates
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    // Debugging output
    cout << "Sorted unique array: ";
    for (int val : a) cout << val << " ";
    cout << endl;

    // Early exits based on conditions
    if (a.front() * 2 > a.back()) {
        cout << 0 << '\n';
        return;
    }
    if (a.front() * 2 >= a.back() && cnt[a.front()] == 1 && cnt[a.back()] == 1) {
        cout << 0 << '\n';
        return;
    }

    // Initialize the answer to a large number
    int ans = INT_MAX;
    int l = -1, r = a.size() - 1;
    int sl = 0, sr = 0;

    // Move right pointer to find valid elements
    while (r >= 0 && a[r] >= a[l + 1] * 2) {
        sr += cnt[a[r]];
        r--;
    }

    ans = min(sl + sr, ans);
    cout << "Initial ans: " << ans << ", sl: " << sl << ", sr: " << sr << endl;

    // Main loop to check conditions
    while (l + 2 < a.size() - 1) {
        ++l;
        sl += cnt[a[l]];
        while (r + 1 < a.size() && a[r + 1] < a[l + 1] * 2) {
            r++;
            sr -= cnt[a[r]];
        }
        // Check current answer
        ans = min(sl + sr, ans);
        cout << "l: " << l << ", r: " << r << ", sl: " << sl << ", sr: " << sr << ", ans: " << ans << endl;
    }

    // Output the final answer
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}