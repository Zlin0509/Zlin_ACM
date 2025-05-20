//
// Created by 27682 on 2025/5/20.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 3e5 + 10;
const ull mask = mt19937_64(time(nullptr))();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

int n, k, q;
string s;

int sum[N][26], cnt[N];
ull res, Hash[N], fac[N], ans[N];
vector<ull> ax;

int len;

inline int get(int i) {
    return i / len;
}

inline void add(int i) {
    res += cnt[Hash[i]]++;
}

inline void del(int i) {
    res -= --cnt[Hash[i]];
}

struct query {
    int qid, l, r;
};

vector<query> op;

bool cmp(const query &a, const query &b) {
    int la = get(a.l), lb = get(b.l);
    if (la != lb) return la < lb;
    return la & 1 ? a.r < b.r : a.r > b.r;
}

inline void Zlin() {
    for (int i = 0; i < 26; i++) fac[i] = rng();
    cin >> n >> k >> q;
    cin >> s, s = ' ' + s;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        op.push_back({i, l, r});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
        sum[i][s[i] - 'a'] = (sum[i][s[i] - 'a'] + 1) % k;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 26; j++) Hash[i] += sum[i][j] * fac[j];
        ax.push_back(Hash[i]);
    }
    sort(ax.begin(), ax.end());
    ax.erase(unique(ax.begin(), ax.end()), ax.end());
    for (int i = 0; i <= n; i++) Hash[i] = lower_bound(ax.begin(), ax.end(), Hash[i]) - ax.begin() + 1;
    len = sqrt(n) + 1;
    sort(op.begin(), op.end(), cmp);
    int l = 0, r = 0;
    res = 0;
    cnt[Hash[0]]++;
    for (auto [id, lx, rx]: op) {
        while (r < rx) add(++r);
        while (r > rx) del(r--);
        while (l + 1 < lx) del(l++);
        while (l + 1 > lx) add(--l);
        ans[id] = res;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
