//
// Created by 27682 on 2025/5/9.
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
set<string> all = {
    "a", "i", "u", "e", "o", "ya", "yu", "yo",
    "ka", "ki", "ku", "ke", "ko", "kya", "kyu", "kyo",
    "ga", "gi", "gu", "ge", "go", "gya", "gyu", "gyo",
    "sa", "si", "su", "se", "so", "sya", "syu", "syo",
    "za", "zi", "zu", "ze", "zo", "zya", "zyu", "zyo",
    "ta", "ti", "tu", "te", "to", "tya", "tyu", "tyo",
    "da", "di", "du", "de", "do",
    "na", "ni", "nu", "ne", "no", "nya", "nyu", "nyo",
    "ha", "hi", "hu", "he", "ho", "hya", "hyu", "hyo",
    "ba", "bi", "bu", "be", "bo", "bya", "byu", "byo",
    "pa", "pi", "pu", "pe", "po", "pya", "pyu", "pyo",
    "ma", "mi", "mu", "me", "mo", "mya", "myu", "myo",
    "ra", "ri", "ru", "re", "ro", "rya", "ryu", "ryo",
    "wa"
};

inline void Zlin() {
    int ans;
    string s;
    cin >> s;
    ans = 0;
    for (int i = 0; i < s.length();) {
        string z;
        z += s[i];
        if (all.find(z) != all.end()) {
            ++ans;
            i++;
            continue;
        }
        if (i + 1 < s.length()) {
            z += s[i + 1];
            if (all.find(z) != all.end()) {
                ++ans;
                i += 2;
                continue;
            }
        }
        if (i + 2 < s.length()) {
            z += s[i + 2];
            if (all.find(z) != all.end()) {
                ++ans;
                i += 3;
                continue;
            }
        }
        ++ans;
        if (s[i] != 'n') {
            i++;
        } else {
            i += 2;
        }
    }
    cout << ans << ' ';

    cin >> s;
    ans = 0;
    for (int i = 0; i < s.length();) {
        string z;
        z += s[i];
        if (all.find(z) != all.end()) {
            ++ans;
            i++;
            continue;
        }
        if (i + 1 < s.length()) {
            z += s[i + 1];
            if (all.find(z) != all.end()) {
                ++ans;
                i += 2;
                continue;
            }
        }
        if (i + 2 < s.length()) {
            z += s[i + 2];
            if (all.find(z) != all.end()) {
                ++ans;
                i += 3;
                continue;
            }
        }
        ++ans;
        if (s[i] != 'n') {
            i++;
        } else {
            i += 2;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
