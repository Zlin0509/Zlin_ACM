//
// Created by 27682 on 2025/7/2.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;

inline void Zlin() {
    priority_queue<int, vi, greater<> > ax, bx, cx;
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &it: a) cin >> it;
    for (int &it: b) cin >> it;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lx = 1e9;
    ll cntl = n - m, cntr = 0;
    for (int i = 0; i < n - m; i++) ax.push(a[i]);
    for (int i = n - m; i < n; i++) {
        if (a[i] > b[i - n + m]) {
            cout << -1 << endl;
            return;
        }
        bx.push(a[i]);
        cx.push(b[i - n + m]);
        cntl -= b[i - n + m] - a[i];
        cntr += b[i - n + m] - a[i];
    }
    while (!bx.empty() && !cx.empty() && bx.top() == cx.top()) {
        lx = min(lx, bx.top());
        bx.pop(), cx.pop();
    }
    if (cntl < 0) {
        cout << -1 << endl;
        return;
    }
    vi ans;
    while (cntl) {
        int x = ax.top(), check1 = x + 1, check2 = lx;
        ax.pop();
        if (!bx.empty()) check2 = min(bx.top(), check2);
        if (check1 <= check2) {
            --cntl;
            ax.push(x + 1);
            ax.pop();
            ans.push_back(x);
        } else if (lx != check2) {
            --cntr;
            ax.push(x);
            ax.pop();
            x = bx.top();
            bx.push(x + 1);
            bx.pop();
            ans.push_back(x);
            while (!bx.empty() && !cx.empty() && bx.top() == cx.top()) {
                lx = min(lx, bx.top());
                bx.pop(), cx.pop();
            }
        } else {
            cout << -1 << endl;
            return;
        }
    }
    while (cntr) {
        --cntr;
        int x = bx.top();
        bx.pop();
        bx.push(x + 1);
        ans.push_back(x);
        while (!bx.empty() && !cx.empty() && bx.top() == cx.top()) {
            lx = min(lx, bx.top());
            bx.pop(), cx.pop();
        }
    }
    cout << n - m << endl;
    for (int it: ans) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
