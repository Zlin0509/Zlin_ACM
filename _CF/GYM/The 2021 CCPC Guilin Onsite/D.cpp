//
// Created by Zlin on 2025/4/13.
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
    vi a(n + 1), b(n + 1), idx(n + 1), tag(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        tag[b[i]] = i;
    }
    vector<pii> op;
    for (int i = 1, l, r; i <= n; i++) {
        if (idx[i] == tag[i]) continue;
        if (idx[i] < tag[i]) {
            cout << -1 << endl;
            return;
        }
        while (idx[i] > tag[i]) {
            l = idx[i] - 1, r = idx[i];
            op.push_back({l, r});
            swap(a[l], a[r]);
            swap(idx[a[l]], idx[a[r]]);
        }
    }
    cout << op.size() << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
