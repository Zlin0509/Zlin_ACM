#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr int N = 2e5 + 10;


inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;

    sort(a.begin(), a.end());
    int tag = a.back();
    a.pop_back();
    vi s;
    s.push_back(tag);
    for (int it: a) s.push_back(it);
    int cnt = 0;
    a.clear();
    set<int> st;
    for (int it: s) {
        st.insert(it);

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
