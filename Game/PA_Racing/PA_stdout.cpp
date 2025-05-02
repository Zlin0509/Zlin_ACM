#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./generator <seed> <T> <magic_hash>\n";
        return 1;
    }

    int seed = stoi(argv[1]);
    int T = stoi(argv[2]);
    mt19937 rng(seed);

    cout << T << '\n';
    while (T--) {
        long long n = uniform_int_distribution<int>(2, 1'000'000)(rng);
        int a1 = uniform_int_distribution<int>(1, 100'000)(rng);
        int b1 = uniform_int_distribution<int>(1, 100'000)(rng);
        int a2 = uniform_int_distribution<int>(1, 100'000)(rng);
        int b2 = uniform_int_distribution<int>(1, 100'000)(rng);
        cout << n << " " << a1 << " " << b1 << " " << a2 << " " << b2 << '\n';
    }

    return 0;
}
