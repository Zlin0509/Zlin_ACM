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

bool bal(const string &s) {
    int c[3] = {0, 0, 0};
    for (char it: s) {
        if (it == 'L') c[0]++;
        else if (it == 'I') c[1]++;
        else c[2]++;
    }
    return (c[0] == c[1] && c[1] == c[2]);
}

char miss(char a, char b) {
    if ((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) return 'T';
    if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) return 'I';
    if ((a == 'I' && b == 'T') || (a == 'T' && b == 'I')) return 'L';
    return '?';
}

inline void Zlin() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c[3] = {0, 0, 0};
    for (char ch: s) {
        if (ch == 'L') c[0]++;
        else if (ch == 'I') c[1]++;
        else c[2]++;
    }
    if (c[0] == n || c[1] == n || c[2] == n) {
        cout << -1 << endl;
        return;
    }

    vi op;
    int mx = 2 * n;
    while (!bal(s) && (int) op.size() < mx) {
        int cnt[3] = {0, 0, 0};
        for (char ch: s) {
            if (ch == 'L') cnt[0]++;
            else if (ch == 'I') cnt[1]++;
            else cnt[2]++;
        }
        char tar = 'L';
        int mn = cnt[0];
        if (cnt[1] < mn || (cnt[1] == mn && 'I' < tar)) {
            tar = 'I';
            mn = cnt[1];
        }
        if (cnt[2] < mn || (cnt[2] == mn && 'T' < tar)) {
            tar = 'T';
            mn = cnt[2];
        }

        bool found = false;
        int pos = -1;
        char ins = '?';
        for (int i = 0; i < (int) s.size() - 1; i++) {
            if (s[i] == s[i + 1]) continue;
            char tmp = miss(s[i], s[i + 1]);
            if (tmp == tar) {
                pos = i;
                ins = tmp;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int i = 0; i < (int) s.size() - 1; i++) {
                if (s[i] == s[i + 1]) continue;
                pos = i;
                ins = miss(s[i], s[i + 1]);
                found = true;
                break;
            }
        }
        if (!found) break;

        op.push_back(pos + 1);
        s.insert(s.begin() + pos + 1, ins);
    }

    if (bal(s)) {
        cout << op.size() << endl;
        for (int p: op) cout << p << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
