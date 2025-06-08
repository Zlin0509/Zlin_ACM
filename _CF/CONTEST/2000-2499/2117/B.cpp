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
    deque<int> q;
    for (int i = n; i; i--) {
        if (i & 1) q.push_back(i);
        else q.push_front(i);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
