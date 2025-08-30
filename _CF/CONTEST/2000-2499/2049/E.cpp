//
// Created by 27682 on 2025/8/29.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k, a[3], len;

inline void Zlin() {
    cin >> n;
    len = n >> 2;
    cout << "? " << 1 << ' ' << len << endl;
    cout.flush();
    cin >> a[0];
    cout << "? " << len + 1 << ' ' << len * 2 << endl;
    cout.flush();
    cin >> a[1];
    len <<= 1;
    cout << "? " << 1 << ' ' << len << endl;
    cout.flush();
    cin >> a[2];
    ll l, r, mid, tmp;
    if (a[0] == a[1]) {
        if (a[2]) {
            l = 1, r = len;
            while (l < r) {
                mid = l + r >> 1;
                cout << "? " << 1 << ' ' << mid << endl;
                cout.flush();
                cin >> tmp;
                if (tmp) r = mid;
                else l = mid + 1;
            }
            k = l;
        } else {
            l = 1, r = len;
            while (l < r) {
                mid = l + r + 1 >> 1;
                cout << "? " << mid << ' ' << n << endl;
                cout.flush();
                cin >> tmp;
                if (tmp) r = mid - 1;
                else l = mid;
            }
            k = n - l + 1;
        }
    } else {
        if (a[2]) {
            l = len + 1, r = n;
            while (l < r) {
                mid = l + r >> 1;
                cout << "? " << 1 << ' ' << mid << endl;
                cout.flush();
                cin >> tmp;
                if (tmp) l = mid + 1;
                else r = mid;
            }
            k = l;
        } else {
            l = len + 1, r = n;
            while (l < r) {
                mid = l + r + 1 >> 1;
                cout << "? " << mid << ' ' << n << endl;
                cout.flush();
                cin >> tmp;
                if (tmp) l = mid;
                else r = mid - 1;
            }
            k = n - l + 1;
        }
    }
    cout << "! " << k << endl;
    cout.flush();
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
