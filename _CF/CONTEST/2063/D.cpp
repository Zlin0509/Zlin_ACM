//
// Created by Zlin on 2025/2/22.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void pre(vi& a, vi& b, stack<ll>& sl, stack<ll>& sr)
{
    stack<ll> st;
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        ll tag = a[r--] - a[l++];
        st.push(tag);
    }
    while (!st.empty())
    {
        sl.push(st.top());
        st.pop();
    }
    l = 0, r = b.size() - 1;
    while (l < r)
    {
        ll tag = b[r--] - b[l++];
        st.push(tag);
    }
    while (!st.empty())
    {
        sr.push(st.top());
        st.pop();
    }
}

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    stack<ll> sl, sr;
    pre(a, b, sl, sr);
    vll ans;
    stack<ll> nl, nr;
    ll res = 0;
    while (1)
    {
        bool t1 = false, t2 = false;
        if (n >= 2 && m >= 1)
            t1 = true;
        if (n >= 1 && m >= 2)
            t2 = true;
        if (t1 && t2)
        {
            if (sl.top() > sr.top())
            {
                res += sl.top();
                nl.push(sl.top());
                sl.pop();
                ans.push_back(res);
                n -= 2, m--;
            }
            else
            {
                res += sr.top();
                nr.push(sr.top());
                sr.pop();
                ans.push_back(res);
                n--, m -= 2;
            }
        }
        else if (t1)
        {
            res += sl.top();
            nl.push(sl.top());
            sl.pop();
            ans.push_back(res);
            n -= 2, m--;
        }
        else if (t2)
        {
            res += sr.top();
            nr.push(sr.top());
            sr.pop();
            ans.push_back(res);
            n--, m -= 2;
        }
        else break;
    }
    while (!nl.empty() && m >= 3)
    {
        res -= nl.top();
        sl.push(nl.top());
        nl.pop();
        n += 2, m++;
        res += sr.top();
        nr.push(sr.top());
        sr.pop();
        n--, m -= 2;
        res += sr.top();
        nr.push(sr.top());
        sr.pop();
        n--, m -= 2;
        ans.push_back(res);
    }
    while (!nr.empty() && n >= 3)
    {
        res -= nr.top();
        sr.push(nr.top());
        nr.pop();
        n++, m += 2;
        res += sl.top();
        nl.push(sl.top());
        sl.pop();
        n -= 2, m--;
        res += sl.top();
        nl.push(sl.top());
        sl.pop();
        n -= 2, m--;
        ans.push_back(res);
    }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
