//
// Created by Zlin on 2024/9/5.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll Base = 133331, Mod = 762417461;
const int N = 2e5 + 5;

ll hd[N], Hash[N], cc;
char a[N];
int n, l, r, mid, cnt, ans;
vi place;

inline bool check(int len) {
    int sum = 0;
    ll c;
    int ll = 0;
    for (auto it: place) {
        c = (Hash[it + len - 1] - Hash[it - 1] * hd[len] % Mod + Mod) % Mod;
        if (it > ll && c == cc) ++sum, ll = it + len - 1;
    }
    return sum >= cnt;
}

inline void init() {
    place.clear();
    ans = l = 0;
    r = n / cnt;
}

inline void Zlin() {
    cin >> n >> cnt >> r;

    init();

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Hash[i] = (Hash[i - 1] * Base + a[i]) % Mod;
    }

    for (int i = 1; i <= n; i++)
        if (a[i] == a[1])
            place.push_back(i);

    while (l < r) {
        mid = l + r + 1 >> 1;
        cc = Hash[mid];
        if (check(mid))
            l = ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    hd[0] = 1;
    for (int i = 1; i < N; i++) hd[i] = hd[i - 1] * Base % Mod;

    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}