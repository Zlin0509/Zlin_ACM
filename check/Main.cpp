#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 10000;
    for (int i = 1; i <= ttt; i++) {
        cout << "Test #" << i << " ... ";
        system("data.exe > data.txt");
        system("WA.exe < data.txt > WA.txt");
        system("AC.exe < data.txt > AC.txt");

        if (system("diff AC.txt WA.txt")) {
            cout << "WA!" << endl;
            cout << "Input:" << endl;
            system("type data.txt");
            cout << endl;
            cout << "WA Output:" << endl;
            system("type WA.txt");
            cout << "AC Output:" << endl;
            system("type AC.txt");
            break;
        }
        cout << "AC" << endl;
    }
    return 0;
}
