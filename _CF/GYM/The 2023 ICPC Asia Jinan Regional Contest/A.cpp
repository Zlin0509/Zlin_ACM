#include<bits/stdc++.h>

using namespace std;

void solve() {
    char s[200010];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') s[i] = ')';
        if (s[i] == '[') s[i] = ']';
    }
    int ans = 0;
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) ans++;
        if (ans >= 3) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}