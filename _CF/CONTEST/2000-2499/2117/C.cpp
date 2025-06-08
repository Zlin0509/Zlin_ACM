//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;


inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1), cnt(n + 1), vis(n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        st.insert(a[i]);
    }
    int check = st.size(), ans = 1;
    for (int i = n; i; i--) {
        --cnt[a[i]];
        if (!cnt[a[i]]) st.erase(a[i]);
        if (vis[a[i]] != ans) {
            --check;
            vis[a[i]] = ans;
        }
        if (!check) {
            check = st.size();
            ++ans;
        }
    }
    cout << ans - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
