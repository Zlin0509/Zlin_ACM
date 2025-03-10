#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, cnt;
string s1, s2;

void Zlin()
{
    cnt = 0;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
            ++cnt;
        if (s2[i] == '1' && !cnt)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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