#include "2/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;
int MAXN = 2e5;  // 数据规模上限

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1,MAXN);
    int m = rnd.next(1,MAXN);
    int x = rnd.next(1,MAXN);

    cout << n << " " << m << " " << x << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << rnd.next(1, MAXN);
        if (i < n) cout << " ";
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << rnd.next(1, MAXN);
        if (i < n) cout << " ";
    }
    cout << "\n";

    for (int i = 1; i <= x; ++i) {
        int t = rnd.next(1, MAXN/2);
        int d = rnd.next(1, MAXN/2);
        cout << t << " " << d << "\n";
    }

    return 0;
}