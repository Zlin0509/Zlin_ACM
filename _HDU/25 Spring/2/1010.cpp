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
unsigned long long Seed;

unsigned myrand()
{
    Seed ^= Seed >> 5;
    Seed ^= Seed << 3;
    return Seed;
}

//template< typename T >void swap(T u,T v){T t=u;u=v;v=t;} //如选手未调用 algorithm 库，请取消注释本行
template <typename T>
void generate(int k, T p[])
{
    //k 为题目中的 k，p[] 为产生的排列存储位置，下标从 1 开始
    auto* q = p + 1;
    for (int i = 1; i <= k; i++)p[i] = i;
    for (int i = k - 1; i > 0; i--)swap(q[i], q[myrand() % i]);
}

constexpr int N = 2e5 + 10;
int n, m, k;
int p[N][33];

inline void Zlin()
{
    cin >> n >> m >> k >> Seed;
    for (int i = 1; i <= n; i++)
        generate(k, p[i]);
    while (m--)
    {
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
