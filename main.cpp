#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll res = 0;
    for (int i = 1; i <= 2e5; i++) res += 1ll * i * log2(i * 3);
    cout << res << endl;
    return 0;
}
