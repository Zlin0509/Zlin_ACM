//
// Created by 27682 on 2025/3/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "! 1 2 3" << endl;
        cout.flush();
        return;
    }
    int a = 1, b = 2, c = 3;
    while (true)
    {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        cout.flush();
        int xx;
        cin >> xx;
        if (!xx)
        {
            cout << "! " << a << ' ' << b << ' ' << c << endl;
            cout.flush();
            return;
        }
        int p = xx;
        cout << "? " << p << ' ' << b << ' ' << c << endl;
        cout.flush();
        int res;
        cin >> res;
        if (!res)
        {
            a = p;
            cout << "! " << a << ' ' << b << ' ' << c << endl;
            cout.flush();
            return;
        }
        cout << "? " << a << ' ' << p << ' ' << c << endl;
        cout.flush();
        cin >> res;
        if (!res)
        {
            b = p;
            cout << "! " << a << ' ' << b << ' ' << c << endl;
            cout.flush();
            return;
        }
        cout << "? " << a << ' ' << b << ' ' << p << endl;
        cout.flush();
        cin >> res;
        if (!res)
        {
            c = p;
            cout << "! " << a << ' ' << b << ' ' << c << endl;
            cout.flush();
            return;
        }
        int z = rand();
        if(z%3==0)
          a = p;
        else if(z%3==1)
          b = p;
        else
          c = p;
    }
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
