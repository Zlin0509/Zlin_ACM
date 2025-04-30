//
// Created by Zlin on 2024/10/15.
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

const ll mo = 998244353;

vector<vll> mul(vector<vll> A, vector<vll> B) {
    int n = A.size();
    vector<vll> C(n, vll(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mo) % mo;
    return C;
}

vector<vll> build(const string &S, char c) {
    int n = S.size();
    vector<vll> F(n + 1, vll(n + 1, 0));
    for (int i = 0; i <= n; ++i) {
        if (i < n && S[i] == c)
            F[i][i + 1] = 1;
        F[i][i] = 1;
    }
    return F;
}

ll cal(const string &S, const string &T) {
    int n = S.size();
    vector<vll> res(n + 1, vll(n + 1, 0));
    for (int i = 0; i <= n; ++i) res[i][i] = 1;
    for (char c: T) {
        vector<vll> Fc = build(S, c);
        res = mul(mul(res, Fc), res);
    }
    return res[0][n];
}

inline void Zlin() {
    string s, t;
    cin >> t >> s;
    cout << cal(s, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}