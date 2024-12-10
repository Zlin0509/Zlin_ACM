//
// Created by Zlin on 2024/11/10.
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

const int N = 2e5 + 5;
const ll mo = 998244353;
struct edge {
    int to, val;

     bool operator<(const edge &x)const{
        return val<x.val;
    }
};
ll dd[N], ss[N];
vector<edge> e[N];
int n, s;
ll ans;

inline ll inv(ll a) {
    ll res = 1, b = mo - 2;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void bfs(int u){

}

inline void Zlin() {
    cin >> n >> s;
    for (int i = 1, u, v, val; i < n; i++) {
        cin >> u >> v >> val;
        e[u].push_back({v, val});
        e[v].push_back({u, val});
    }
    ans = 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd[0] = 1;
    ss[0] = 1;
    for (int i = 1; i <= 200010; i++) {
        ss[i] = (ss[i - 1] * i + 1) % mo;
        dd[i] = dd[i - 1] * i % mo;
    }
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}