//
// Created by Zlin on 2025/2/7.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    for (int i = 1; i <= ttt; i++)
    {
        system("../cmake-build-debug/data > data.txt");
        system("../cmake-build-debug/AC < data.txt > AC.txt");
        system("../cmake-build-debug/WA < data.txt > WA.txt");
        cout << "test " << i << ':';
        if (system("diff ../cmake-build-debug/AC.txt ../cmake-build-debug/WA.txt"))
        {
            cout << "WA" << '\n';
            return 0;
        }
        cout << "AC" << '\n';
    }
    return 0;
}
