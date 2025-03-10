//
// Created by 27682 on 2025/2/27.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    int cnt = 0;
    for (int &it: a)
        cin >> it, cnt += it == 0;
    if (cnt != 1) {
        cout << "NO" << endl;
        return;
    }
    vector aa(n + 1, vi());
    for (int i = 0; i < n; i++)
        aa[a[i]].push_back(i);
    set<int> have;
    have.insert(aa[0][0]);
    for (int i = 1; i <= n; i++) {
        for (int id: aa[i]) {
            bool check = false;
            auto it = have.lower_bound(id);
            if (it != have.end() && a[*it] == a[id] - 1)
                check = true;
            if (it != have.begin() && a[*prev(it)] == a[id] - 1)
                check = true;
            if (!check) {
                cout << "NO" << endl;
                return;
            }
        }
        for (int id: aa[i])
            have.insert(id);
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}