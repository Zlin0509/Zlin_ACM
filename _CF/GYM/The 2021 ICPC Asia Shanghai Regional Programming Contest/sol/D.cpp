#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff double
using namespace std;

int p, q;
int sqr(int x) { return x * x; }
void solve() {
    cin >> p >> q;
    int tmp = sqr(p) - sqr(2 * q);
    if(tmp < 0) {cout << "0 0\n"; return ;}
    ff s = sqrt(tmp);
    if(s == (int)s) {
        int ans1 = s + p;
        int ans2 = q * 2;
        int g = gcd(ans1, ans2);
        cout << ans1 / g << " " << ans2 / g << endl;
    } else {
        cout << "0 0\n"; return ;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t --) solve();

    return 0;
}