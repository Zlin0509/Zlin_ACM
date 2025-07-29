#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
const int N = 2e5 + 7;
int a[N];
int sg[1005][1005];
int s;
int pre[N];
int getsg(int l,int r) {
    if (sg[l][r])return sg[l][r];
    if (pre[r] - pre[l - 1] <= s)return 0;
    set<int> st;
    if (l + 1 < r) {
        getsg(l + 1, r);
        st.insert(sg[l + 1][r]);
    }
    if (l < r - 1) {
        getsg(l, r - 1);
        st.insert(sg[l][r - 1]);
    }
    for (int i = 0;; i++) {
        if (!st.count(i)) {
            sg[l][r] = i;
            return sg[l][r];
        }
    }
}

void solved() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= 30; i++) {
        s = i;
        for (int l = 0; l <= n; l++) for (int r = 0; r <= n; r++) sg[l][r] = 0;
        cout << i << ' ' << getsg(1, n) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    // cin>>_;
    while (_--)solved();
}
