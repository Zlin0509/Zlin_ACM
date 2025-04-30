//
// Created by Zlin on 2025/4/20.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    string tag[6];
    for (int i = 0; i < 6; i++) cin >> tag[i];
    int cnt = 0;
    for (int i = 0; i < 3; i++) cnt += tag[i] != tag[i + 3];
    if (cnt == 0) {
        cout << 8 << endl;
    } else if (cnt == 1) {
        cout << 6 << endl;
    } else if (cnt == 2){
        cout << 5 << endl;
    } else {
        cout << 4 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
