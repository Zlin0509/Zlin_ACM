//
// Created by Zlin on 2025/3/29.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vi cnt(2, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            cnt[i & 1]++;
        }
        if (b[i] == '0') {
            cnt[i + 1 & 1]++;
        }
    }
    bool check = true;
    if (cnt[0] < n / 2 + n % 2 || cnt[1] < n / 2) check = false;
    cout << (check ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
