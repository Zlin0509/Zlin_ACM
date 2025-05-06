//
// Created by Zlin on 2025/5/1.
//

#include <bits/stdc++.h>

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
    string a, b;
    cin >> n >> a >> b;
    int cnt[26];
    for (char it: a) cnt[it - 'a']++;
    for (char it: b) cnt[it - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            cout << "NO" << endl;
            return;
        }
    }
    int tag = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            ++tag;
        }
    }
    if (tag > 1 || (tag == 1 && !(n & 1))) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
