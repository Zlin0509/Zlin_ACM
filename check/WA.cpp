#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
const int N = 3e5 + 7;
int a[N];
int b[N];

void solved() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    int cnt2 = 0;
    for (int i = n - m + 1; i <= n; i++) {
        if (a[i] > b[i - n + m]) {
            cout << -1 << '\n';
            return;
        }
        cnt2 += b[i - n + m] - a[i];
    }
    if (cnt2 > n - m) {
        cout << -1 << '\n';
        return;
    }
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= n - m; i++) {
        pq.push(a[i]);
    }
    int all = n - m;
    int cnt1 = all - cnt2;
    vector<int> ans;
    while (cnt1) {
        if (pq.size() == 0) {
            cout << -1 << '\n';
            return;
        }
        int x = pq.top();
        int y = x + 1;
        pq.pop();
        pq.push(y);
        if (pq.top() > a[n - m + 1]) {
            cout << -1 << '\n';
            return;
        }
        if (pq.size() == 0) {
            cout << -1 << '\n';
            return;
        }
        pq.pop();
        ans.push_back(x);
        cnt1--;
    }
    if (pq.size() != cnt2 or pq.top() > a[n - m + 1] + 1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = n - m + 1; i <= n; i++) {
        while (b[i + m - n] > a[i]) {
            ans.push_back(a[i]);
            a[i]++;
        }
    }
    multiset<int> st;
    for (int i = 1; i <= n; i++) st.insert(a[i]);
    for (int it: ans) {
        st.erase(st.find(it));
        st.insert(it + 1);
        st.erase(st.begin());
    }
    int check = 1;
    for (int i = 1; i <= m; i++) {
        if (*st.begin() != b[i]) {
            check = 0;
        }
        st.erase(st.begin());
    }
    cout << check << endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)solved();
    return 0;
}
