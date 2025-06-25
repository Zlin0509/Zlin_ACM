#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int n;
ll a[N], st_min[N][20], st_gcd[N][20];
int LOG[N];

void init() {
    LOG[0] = -1;
    for (int i = 1; i <= n; i++) LOG[i] = LOG[i >> 1] + 1;
    for (int i = 1; i <= n; i++) {
        st_min[i][0] = st_gcd[i][0] = a[i];
    }
    for (int k = 1; k <= LOG[n]; k++) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            st_min[i][k] = min(st_min[i][k - 1], st_min[i + (1 << k - 1)][k - 1]);
            st_gcd[i][k] = __gcd(st_gcd[i][k - 1], st_gcd[i + (1 << k - 1)][k - 1]);
        }
    }
}

ll query_min(int l, int r) {
    int k = LOG[r - l + 1];
    return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
}

ll query_gcd(int l, int r) {
    int k = LOG[r - l + 1];
    return __gcd(st_gcd[l][k], st_gcd[r - (1 << k) + 1][k]);
}

bool check1(int x, int i) {
    if (x > i - 1 || query_min(x, i - 1) <= a[i]) return false;
    if (x > i || query_gcd(x, i) != a[i]) return false;
    return true;
}

bool check2(int x, int i) {
    if (i + 1 > x || query_min(i + 1, x) < a[i]) return false;
    if (i > x || query_gcd(i, x) != a[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int L, R, l, r;
        l = 1, r = i;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check1(mid, i)) r = mid;
            else l = mid + 1;
        }
        L = r;
        l = i, r = n + 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check2(mid, i)) l = mid;
            else r = mid - 1;
        }
        R = l;
        cout << L << ' ' << R << endl;
        ans += (i - L + 1) * (R - i + 1);
        //cout <<i<<" "<<L<<" "<<R<<'\n';
    }
    cout << ans << '\n';
    return 0;
}
