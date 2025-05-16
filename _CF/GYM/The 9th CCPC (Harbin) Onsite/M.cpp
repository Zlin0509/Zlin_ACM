//
// Created by Zlin on 2025/5/16.
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

struct ops {
    int tag;
    ll x1, y1, x2, y2, r;
    char col;
};

vector<ops> op;

int n;

inline char cal(ll i, ll j) {
    char res = '.';
    for (auto it: op) {
        if (it.tag == 1) {
            ll x = it.x1, y = it.y1, r = it.r;
            if ((x - i) * (x - i) + (j - y) * (j - y) <= r * r) res = it.col;
        } else {
            ll x1 = it.x1, y1 = it.y1, x2 = it.x2, y2 = it.y2;
            if (i >= x1 && i <= x2 && j >= y1 && j <= y2) res = it.col;
        }
    }
    return res;
}

inline void Zlin() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        ops z;
        if (s == "Circle") {
            cin >> z.x1 >> z.y1 >> z.r >> z.col;
            z.tag = 1;
            op.push_back(z);
        } else if (s == "Rectangle") {
            cin >> z.x1 >> z.y1 >> z.x2 >> z.y2 >> z.col;
            z.tag = 2;
            op.push_back(z);
        } else {
            int lx, rx, ly, ry;
            cin >> lx >> ly >> rx >> ry;
            for (int j = ry; j >= ly; j--) {
                for (int i = lx; i <= rx; i++) {
                    cout << cal(i, j);
                }
                cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
