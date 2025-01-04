//
// Created by 27682 on 2024/12/31.
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

string dd;

inline void Zlin() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;

    for (int i = 1; i <= 19; i++) dd += "9";
    dd += "8";
    for (int i = 1; i <= 20; i++) dd += "9";

    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}