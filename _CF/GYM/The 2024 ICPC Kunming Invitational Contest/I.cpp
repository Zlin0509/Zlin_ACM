//
// Created by Zlin on 2024/10/3.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    string x;
    cin >> x;
    int c = 1, ans = 0, l = 1;
    bool check = false;
    if (x[0] == x[x.length() - 1]) {
        for (; l < x.length(); l++)
            if (x[l] != x[l - 1]) break;
        string z = x;
        for (int i = l; i < x.length(); i++)
            z[i - l] = x[i];
        for (int i = 0; i < l; i++)
            z[i - l + x.length()] = x[i];
        x = z;
    }
    for (int i = 1; i < x.length(); i++) {
        if (x[i] == x[i - 1])++c;
        else {
            ans += c / 2;
            if (c % 2 == 0) check = true;
            c = 1;
        }
    }
    ans += c / 2;
    if (c % 2 == 0) check = true;
    if (check && x[0] != x[x.length() - 1]) --ans;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}