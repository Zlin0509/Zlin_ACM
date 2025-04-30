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
    int n, check = 0, l = 0;
    cin >> n;
    vi ans;
    while (l < n) {
        if (!(check ^ l)) {
            if (l + 1 == n) {
                cout << "impossible\n";
                return;
            } else {
                check ^= l + 1;
                ans.push_back(l + 1);
                check ^= l;
                ans.push_back(l);
                l += 2;
            }
        } else {
            check ^= l;
            ans.push_back(l++);
        }
    }
    for (int it: ans) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}