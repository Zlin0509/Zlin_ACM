//
// Created by 27682 on 2025/5/9.
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

constexpr int N = 2010;

int n, q, len;
int a[N], lx[N], rx[N], ans[N];
vi have[N];

int cnt[N], res, used[N];

struct Query {
    int qid, l, r;
} op[N];

int get(int i) {
    return i / len;
}

multiset<int> now;

void add(int i, int lx, int rx) {
    if (cnt[i] && !used[i]) ++res, used[i] = 1, now.insert(i);
    for (int it: have[i]) {
        if (!cnt[it] && it >= lx && it <= rx && !used[it]) ++res, used[it] = 1, now.insert(i);
        ++cnt[it];
    }
}

void del(int i, int lx, int rx) {
    if (used[i]) --res, used[i] = 0, now.erase(now.find(i));
    for (int it: have[i]) {
        --cnt[it];
        if (!cnt[it] && it >= lx && it <= rx && used[i]) --res, used[i] = 0, now.erase(now.find(i));
    }
}

bool cmp(const Query &a, const Query &b) {
    int la = get(a.l), lb = get(b.l);
    if (la != lb) return la < lb;
    return (la & 1) ? (a.r < b.r) : (a.r > b.r);
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[i]) {
                have[i].push_back(j);
            }
        }
    }
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
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
