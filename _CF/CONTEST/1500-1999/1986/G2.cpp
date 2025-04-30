//
// Created by Zlin on 2024/9/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 5e5 + 5;
vi su[N];
int n, p[N], a[N], b[N], sum[N];
vi aa[N], bb[N];
ll ans;

inline void Zlin() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int x = gcd(i, p[i]);
        a[i] = p[i] / x, b[i] = i / x;
    }
    for (int i = 1; i <= n; i++)aa[a[i]].push_back(i), bb[b[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
        for (int j: bb[i]) for (int x: su[a[j]]) ++sum[x];
        for (int j = i; j <= n; j += i) for (int x: aa[j]) ans += sum[b[x]];
        for (int j: bb[i]) for (int x: su[a[j]]) --sum[x];
    }
    for (int i = 1; i <= n; i++) if (a[i] % b[i] == 0)--ans;
    cout << ans / 2 << '\n';
    for (int i = 1; i <= n; i++) aa[a[i]].clear(), bb[b[i]].clear();
}

inline void db() {
    for (int i = 1; i < N; i++)
        for (int j = 1; j * i < N; j++)
            su[i * j].push_back(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    db();
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}