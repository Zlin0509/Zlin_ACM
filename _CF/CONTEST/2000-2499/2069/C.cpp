#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Precompute powers of 2 and their inverses.
    // Maximum exponent we need is at most 200000 (since n<=2e5).
    const int MAX = 200005;
    vector<long long> p2(MAX+1, 0), inv2(MAX+1, 0);
    p2[0] = 1;
    for (int i = 1; i <= MAX; i++){
        p2[i] = (p2[i-1] * 2) % MOD;
    }
    // Compute inverse of 2 modulo MOD using Fermat's little theorem.
    long long inv_two = 1;
    {
        long long base = 2, exp = MOD - 2;
        while(exp){
            if(exp & 1)
                inv_two = (inv_two * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
    }
    inv2[0] = 1; // 2^0 inverse is 1.
    for (int i = 1; i <= MAX; i++){
        inv2[i] = (inv2[i-1] * inv_two) % MOD;
    }

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        // Build prefix sum for the count of 2's.
        // prefix2[i] = number of 2's in indices [0, i-1].
        vector<int> prefix2(n+1, 0);
        for (int i = 0; i < n; i++){
            prefix2[i+1] = prefix2[i] + (a[i] == 2);
        }

        long long ans = 0;
        long long ones_sum = 0; // will hold sum of 2^{-prefix2[i+1]} for positions i where a[i]==1.
        long long ones_count = 0; // number of 1's seen so far.

        for (int i = 0; i < n; i++){
            if(a[i] == 1){
                // When we see a 1 at index i, add its weight.
                // Weight is 2^{-prefix2[i+1]}.
                ones_sum = (ones_sum + inv2[prefix2[i+1]]) % MOD;
                ones_count++;
            } else if(a[i] == 3){
                // For a 3 at index i, let X = prefix2[i] (i.e. count of 2's in [0, i-1]).
                int X = prefix2[i];
                long long contrib = (p2[X] * ones_sum) % MOD;
                contrib = (contrib - ones_count) % MOD;
                if(contrib < 0)
                    contrib += MOD;
                ans = (ans + contrib) % MOD;
            }
            // For a[i]==2, no immediate update is needed.
        }

        cout << ans % MOD << "\n";
    }

    return 0;
}
