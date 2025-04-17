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

string s;

inline void Zlin() {
    getline(cin, s);
    cout << s << endl;
    cout << "AI: ";
    vector<string> ans;
    string now;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            now += s[i];
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            now += s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
            now += s[i];
        } else {
            if (!now.empty()) {
                ans.push_back(now);
                now.clear();
            }
            if (s[i] == ' ') {
                if (!ans.empty() && ans.back() != " ") ans.push_back(" ");
            } else {
                while (!ans.empty() && ans.back() == " ") ans.pop_back();
                now = s[i];
                ans.push_back(now);
                now.clear();
            }
        }
    }
    if (!now.empty()) {
        ans.push_back(now);
        now.clear();
    }
    while (!ans.empty() && ans.back() == " ") ans.pop_back();
    for (int i = 0, r; i < ans.size(); i++) {
        if (ans[i] == "I" || ans[i] == "me") {
            ans[i] = "you";
            continue;
        }
        if (ans[i] == "?") {
            ans[i] = '!';
            continue;
        }
        for (char &it: ans[i])
            if (it >= 'A' && it <= 'Z' && it != 'I')
                it += 'a' - 'A';

        for (r = i + 1; r < ans.size(); r++) {
            if (ans[r][0] >= 'a' && ans[r][0] <= 'z') {
                break;
            }
            if (ans[r][0] >= 'A' && ans[r][0] <= 'Z') {
                break;
            }
            if (ans[r][0] >= '0' && ans[r][0] <= '9') {
                break;
            }
        }
        if (r != ans.size()) {
            if (ans[r] != "I") {
                for (char &it: ans[r]) {
                    if (it >= 'A' && it <= 'Z' && it != 'I')
                        it += 'a' - 'A';
                }
            }
            if (ans[i] == "can" && ans[r] == "you") {
                ans[i] = "I";
                ans[r] = "can";
                continue;
            }
            if (ans[i] == "could" && ans[r] == "you") {
                ans[i] = "I";
                ans[r] = "could";
                continue;
            }
        }

    }
    for (auto it: ans)
        cout << it;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    getline(cin, s);
    while (ttt--) Zlin();
    return 0;
}
