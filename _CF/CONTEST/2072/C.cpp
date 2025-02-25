#include <bits/stdc++.h>
using namespace std;

// returns floor(log2(x)) for x>=1
int flog(int x) {
    return 31 - __builtin_clz(x);
}

// f(r) = OR of all numbers from 0 to r-1. For r>0 one may show that:
// f(r) = 2^(floor(log2(r)) + 1) - 1.
int f(int r) {
    if(r == 0) return 0;
    int k = flog(r);
    return (1 << (k+1)) - 1;
}

// Given x, compute L = MEX(T) where T = { a : a & ~x == 0 }.
// If x is of the form 2^k-1 then every number 0..x is allowed so L = x+1.
// Otherwise, let b0 be the smallest bit with x not having 1; then L = 2^b0.
int getL(int x) {
    // if x is 2^k - 1, then L = x+1.
    // Otherwise, find smallest bit i with (x>>i)&1==0.
    for (int i = 0; i < 31; i++) {
        if (((x >> i) & 1) == 0) {
            return 1 << i;
        }
    }
    // if x has bits 0..30 all 1 then L = x+1 (x < 2^30 by problem statement)
    return x + 1;
}

// We decide on a candidate r (which will be the MEX of our key’s distinct values)
// by testing from r = min(n, L) down to 0.
int choose_r(int n, int x) {
    int L = getL(x);
    int r_max = min(n, L);
    for (int r = r_max; r >= 0; r--) {
        // r==0 is always feasible (we then simply choose {x})
        if(r == 0) return 0;
        int u = f(r);
        if(u == x) {
            // including 0,...,r-1 gives OR = x, and we used r numbers
            return r;
        } else {
            // if u != x we need one extra slot to “fix” the OR (for example by adding x)
            if(n >= r+1 && x >= r) return r;
        }
    }
    return 0; // fallback
}

// After choosing r (the MEX we want to achieve), we build our answer.
void solve_case() {
    int n, x;
    cin >> n >> x;
    int L = getL(x);
    int r = choose_r(n, x);

    vector<int> ans;
    // if r > 0, include all numbers 0,...,r-1
    if(r > 0) {
        for (int i = 0; i < r; i++)
            ans.push_back(i);
    }
    // Check if these r numbers already “cover” x via OR:
    if(f(r) != x) {
        // We need to add an extra element that covers the missing bits.
        // (x is always allowed and (x OR f(r)) = x.)
        ans.push_back(x);
    }
    // Now ans contains the distinct numbers that determine the MEX.
    // Let d = ans.size(). (It is either r or r+1.)
    int d = ans.size();
    // We must output exactly n numbers. Duplicates do not change the MEX.
    while(ans.size() < (size_t)n) {
        // Append any number from ans – here we choose 0.
        ans.push_back(ans[0]);
    }
    // (If ans.size() > n it would be a bug – our feasibility check guarantees that doesn’t happen.)

    // Output the answer.
    for (int a : ans)
        cout << a << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve_case();
    }
    return 0;
}
