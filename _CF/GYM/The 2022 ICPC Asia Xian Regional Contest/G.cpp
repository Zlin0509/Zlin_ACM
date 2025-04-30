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

map<string, int> have;
vector<string> a;

bool cmp(const string a, const string b) {
    return a.length() < b.length();
}

inline void Zlin() {
    int n;
    cin >> n;
    string x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    for (auto s: a) {
        if (s.length() == 1) {
            ans = max(ans, 1);
            have[s] = 1;
        } else {
            string l, r;
            for (int i = 0; i < s.length() - 1; i++) l += s[i];
            for (int i = 1; i < s.length(); i++) r += s[i];
            if (have[l] && have[r]) {
                ans = max(ans, (int) s.length());
                have[s] = 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}