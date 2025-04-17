//
// Created by Zlin on 2025/1/16.
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

inline void Zlin() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
        if (b < 130) {
            cout << "duo chi yu! ";
        } else if (b == 130) {
            cout << "wan mei! ";
        } else {
            cout << "ni li hai! ";
        }
        if (c < 27) {
            cout << "duo chi rou!";
        } else if (c == 27) {
            cout << "wan mei!";
        } else {
            cout << "shao chi rou!";
        }
    } else {
        if (b < 129) {
            cout << "duo chi yu! ";
        } else if (b == 129) {
            cout << "wan mei! ";
        } else {
            cout << "ni li hai! ";
        }
        if (c < 25) {
            cout << "duo chi rou!";
        } else if (c == 25) {
            cout << "wan mei!";
        } else {
            cout << "shao chi rou!";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
