//
// Created by 27682 on 2025/3/25.
//
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


inline void Zlin() {
    int n, q;
    cin >> n >> q;
    string s;
    set<int> l, r;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '(')
                l.insert(i);
            else
                r.insert(i);
        }
    }
    int x;
    while (q--) {
        cin >> x;
        if (n & 1) {
            cout << "NO" << endl;
            continue;
        }
        if (x != 1 && s[x] == s[x - 1]) {
            if (s[x] == '(') {
                l.erase(x - 1);
            } else {
                r.erase(x - 1);
            }
        }
        if (x != n && s[x] == s[x + 1]) {
            if (s[x] == '(') {
                l.erase(x);
            } else {
                r.erase(x);
            }
        }
        s[x] = s[x] == '(' ? ')' : '(';
        if (x != n && s[x] == s[x + 1]) {
            if (s[x] == '(') {
                l.insert(x);
            } else {
                r.insert(x);
            }
        }
        if (x != 1 && s[x] == s[x - 1]) {
            if (s[x] == '(') {
                l.insert(x - 1);
            } else {
                r.insert(x - 1);
            }
        }
        if (s[1] == ')' || s[n] == '(') cout << "NO" << endl;
        else if (l.empty() && r.empty()) cout << "YES" << endl;
        else if (l.empty() || r.empty()) cout << "NO" << endl;
        else if (*l.begin() < *r.begin() && *l.rbegin() < *r.rbegin()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
