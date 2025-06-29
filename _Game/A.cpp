#include <bits/stdc++.h>
// #define endl '\n'
#define t1(x) ((x)*2)
#define t2(x) ((x)*2+1)
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr int N = 5010;
constexpr int INF = 1000;

queue<int> idx[26];
string s;
int k;

inline void Zlin() {
    cin >> s >> k;
    k = s.length() - k;
    for (int i = 0; i < s.length(); i++) idx[s[i] - 'a'].push(i + 1);
    int tag = 0;
    string ans;
    for (int i = 0; i < 26; i++) {
        if (idx[i].empty()) continue;
        if (idx[i].front() <= k) {
            k -= idx[i].front();
            ans += char('a' + i);
            tag = idx[i].front();
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        while (!idx[i].empty() && idx[i].front() <= tag) idx[i].pop();
        if (idx[i].empty()) continue;
        if (idx[i].front() - tag - 1 <= k) {
            ans += char('a' + i);
            tag = idx[i].front();
            break;
        }
    }
    for (int i = tag + 1; i <= tag + k - 3; i++) ans += s[tag + i];
    char c = 'z';
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
