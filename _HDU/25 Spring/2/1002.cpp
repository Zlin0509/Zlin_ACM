//
// Created by 27682 on 2025/3/14.
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

string l[] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
string r[] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

inline void Zlin()
{
    string s;
    cin >> s;
    int lx = 0, rx = 0;
    for (int i = 1984; i <= 2043; i++)
    {
        string c = l[lx] + r[rx];
        if (c == s)
        {
            cout << i << endl;
            return;
        }
        lx = (lx + 1) % 10, rx = (rx + 1) % 12;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
