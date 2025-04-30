#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int n, c;
int a[55], cnt[55];
void Zlin()
{
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ++cnt[a[i]];
    for (int i = n; i >= 1; i--)
        if (cnt[i] & 1)
        {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}