//
// Created by Zlin on 2024/10/14.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int inf = 1e4;
const db N = 1e3;

int main() {
    srand(time(0));
    int n = random() % inf;
    db p1 = random() % n, p2 = random() % n;
    db v1 = random() % inf, v2 = random() % inf;
    cout << (db) n / N << ' ' << p1 / N << ' ' << v1 / N << ' ' << p2 / N << ' ' << v2 / N;
}