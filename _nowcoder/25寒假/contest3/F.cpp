//
// Created by Zlin on 2025/1/26.
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

inline void Zlin()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int sum = a + b + c;
    if (sum < n || sum / 2 > n)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
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
