#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 10000;
    for (int i = 1; i <= ttt; i++) {
        cout << "Test #" << i << " ... ";
        system("/Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/data > data.txt");
        system("/Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/WA < /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/data.txt > /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/WA.txt");
        system("/Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/AC < /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/data.txt > /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/AC.txt");
        if (system("fc /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/AC.txt /Users/zlin/Desktop/Project/Code/Zlin_ACM/cmake-build-debug/WA.txt")) {
            cout << "WA!" << endl;
            break;
        }
        cout << "AC" << endl;
    }
    return 0;
}
