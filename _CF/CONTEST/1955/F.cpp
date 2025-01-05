//
// Created by Zlin on 2024/9/2.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

inline void Zlin() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << a / 2 + b / 2 + c / 2 + d / 2 + (a % 2 && b % 2 && c % 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}