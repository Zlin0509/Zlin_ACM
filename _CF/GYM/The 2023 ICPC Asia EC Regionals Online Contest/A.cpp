//
// Created by Zlin on 2024/10/18.
//

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

inline void Zlin() {
    int n, m;
    queue<string> a, b, c;
    map<string, int> useda, usedb, cc;
    string x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (!useda[x]) {
            useda[x]++;
            a.push(x);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (!usedb[x]) {
            usedb[x]++;
            b.push(x);
        }
    }
    while (!a.empty() && !b.empty()) {
        c.push(a.front());
        a.pop();
        c.push(b.front());
        b.pop();
    }
    while (!a.empty()) {
        c.push(a.front());
        a.pop();
    }
    while (!b.empty()) {
        c.push(b.front());
        b.pop();
    }
    while (!c.empty()) {
        x = c.front(), c.pop();
        if (!cc[x]) {
            cout << x << '\n';
            ++cc[x];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}