//
// Created by 27682 on 2025/4/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    queue<int> s[26];
    for (int i = 0; i < n; i++) {
        s[a[i] - 'a'].push(i);
    }
    for (int i = 0, tag; i < m; i++) {
        tag = b[i] - 'a';
        if (!s[tag].empty()) {
            for (int j = 0; j < tag; j++) {
                while (!s[j].empty() && s[j].front() < s[tag].front()) {
                    s[j].pop();
                }
            }
            s[tag].pop();
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
