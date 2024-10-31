//
// Created by Zlin on 2024/10/31.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

vector<char> ans;
int n;
queue<int> q;
stack<int> s1, s2;

inline void Zlin() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        q.push(x);
    }
    int tag = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        while (!s1.empty() && s1.top() == tag) {
            ++tag;
            ans.push_back('b');
            s1.pop();
        }
        if (s1.empty() || s1.top() > u) {
            s1.push(u);
            ans.push_back('a');
        } else if (s2.empty() || s2.top() > u) {
            s2.push(u);
            ans.push_back('c');
        } else {
            while (!s2.empty() && s2.top() == tag) {
                ++tag;
                ans.push_back('d');
                s2.pop();
            }

            if (s2.empty() || s2.top() > u) {
                s2.push(u);
                ans.push_back('c');
            } else {
                cout << 0;
                return;
            }
        }
    }
    while (!s1.empty() && !s2.empty()) {
        if (s1.top() == tag) {
            s1.pop();
            ans.push_back('b');
        } else {
            s2.pop();
            ans.push_back('d');
        }
        ++tag;
    }
    while (!s1.empty()) {
        s1.pop();
        ans.push_back('b');
        ++tag;
    }
    while (!s2.empty()) {
        s2.pop();
        ans.push_back('d');
        ++tag;
    }
    for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ' ';
    cout << ans.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}