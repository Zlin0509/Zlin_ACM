//
// Created by 27682 on 2025/3/10.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    stack<char> have;
    string c;
    int l = 0, r = 0;
    for (auto it : s)
    {
        if (have.empty())
            have.push(it);
        else if (it == have.top())
            have.push(it);
        else
        {
            if (it == ')' && have.top() == '(')
                have.pop();
            else
            {
                while (!have.empty())
                {
                    c += have.top();
                    have.pop();
                }
                have.push(it);
            }
        }
    }
    l = c.length(), r = have.size();
    if (l > r) swap(l, r);
    ll ans = 0;
    while (l >= 2)
    {
        l -= 2, r -= 2;
        ans += min(a, b * 2);
    }
    if (!l) ans += r / 2 * b;
    else ans += min((r / 2 + 2) * b, a + r / 2 * b);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
