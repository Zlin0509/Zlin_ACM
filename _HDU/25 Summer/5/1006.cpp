#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e5 + 6;
const int MAXN = 500010;
const int M = 30;
const ll inf = 1e18;
const ll mod = 998244353;
ll n, sg[N], cnt[N];
bool vis[100];

ll getmex() {
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            return i;
        }
    }
}

void solve() {
    n = 10000;
    sg[0] = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= i; j++) {
            ll len1 = max(0, j - 1 - 1);
            ll len2 = max(0, i - j - 1);
            vis[sg[len1] ^ sg[len2]] = 1;
        }
        sg[i] = getmex();
    }
    for (int i = 137; i <= 136 * 3; i++) {
        // if(sg[i]==0){
        //     cout << i << "\n";
        // }
        // cnt[sg[i]]++;
        cout << sg[i] << " ";
        // if(sg[i]==1){
        //     cout <<i << " " << i%8 << "\n" ;
        // }
    }
    for (int i = 0; i <= n; i++) {
        // cout <<i << " "<< cnt[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
