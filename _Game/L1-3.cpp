//
// Created by Zlin on 2025/1/16.
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
    string s;
    cin >> s;
    if (s.length() == 6) {
        for (int i = 0; i < 4; i++) cout << s[i];
        cout << '-';
        for (int i = 4; i < 6; i++) cout << s[i];
    } else {
        int x = (s[0] - '0') * 10 + s[1] - '0';
        if (x < 22) {
            cout << 20;
        } else {
            cout << 19;
        }
        for (int i = 0; i < 2; i++) cout << s[i];
        cout << '-';
        for (int i = 2; i < 4; i++) cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
