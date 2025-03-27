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

string s[40];
string c1 = "easy", c2 = "qiandao", it;
string ans = "Wo AK le";

int main() {
    int n, m;
    cin >> n >> m;
    for (int q = 0; q < n; q++) {
        getline(cin, it);
        bool check = false;
        for (int j = 0; j < it.length(); j++) {
            for (int k = 0; k < c1.length(); k++) {
                if (j + k >= it.length() || it[j + k] != c1[k])
                    break;
                if (k == c1.length() - 1)
                    check = true;
            }
            if (check) break;
            for (int k = 0; k < c2.length(); k++) {
                if (j + k >= it.length() || it[j + k] != c2[k])
                    break;
                if (k == c2.length() - 1)
                    check = true;
            }
            if (check) break;
        }
        if (check) continue;
        if (!m) {
            ans = it;
        }
        --m;
    }
    cout << ans;
    return 0;
}
