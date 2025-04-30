//
// Created by Zlin on 2025/4/4.
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

constexpr int N = 5e4;

vi e[N];

inline void Zlin() {
    int n;
    string s;
    cin >> n;
    int cnt = 1, now = 1;
    vector<string> have;
    map<string, int> m;
    map<int, string> mx;
    string nows = "main";
    while (n--) {
        cin >> s;
        if (s == "commit") {
            e[++cnt].push_back(now);
            m[nows] = cnt;
            now = cnt;
            mx[now] = nows;
        } else if (s == "branch") {
            cin >> s;
            if (m[s]) continue;
            nows = s;
            now = ++cnt;
            m[nows] = now;
            mx[cnt] = nows;
        } else if (s == "checkout") {
            cin >> s;
            now = m[s];
            nows = s;
        } else if (s == "reset"){
            int c;
            cin >> c;
            now = c;
            nows = mx[c];
        } else {
            cin >> s;
        }
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
