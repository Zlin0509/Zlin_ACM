//
// Created by Zlin on 2024/10/7.
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

ull s1[105], s2[105], s3[105];

inline void Zlin() {
    ull n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i] >> s3[i];
    }
    ull l = 0, r = 2e18;
    while (l < r) {
        ull mid = (l + r) / 2;
        ull tot = 0;
        for (int i = 1; i <= n; i++) {
            ll q = mid % (s1[i] * s2[i] + s3[i]);
            tot += mid / (s1[i] * s2[i] + s3[i]) * s2[i];
            tot += min(s2[i], q / s1[i]);
            if (tot >= k) {
                break;
            }
        }
        if (tot >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
        //cout<<l<<"\n";
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}