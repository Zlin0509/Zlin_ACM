#include<bits/stdc++.h>
using namespace std;


int main() {

    int t = 1;
    cin >> t;
    while (t--) {
        int N, M, K, D;
        cin >> N >> M >> K >> D;
        vector<long long> a(N);
        for (int i = 0; i < N; i++) {
            vector<long long> dp(M, 1e9);
            vector<int> v(M);
            multiset<long long> mst = {1};
            dp[0] = 1;
            cin >> v[0];
            for (int j = 1; j < M - 1; j++) {
                cin >> v[j];
                dp[j] = *mst.begin() + v[j] + 1;
                if (j - D - 1 >= 0)
                    mst.erase(mst.find(dp[j - D - 1]));
                mst.insert(dp[j]);
            }
            cin >> v.back();
            dp.back() = 1 + *mst.begin();
            a[i] = dp.back();
        }

        long long cur = 0;
        for (int i = 0; i < K; i++)
            cur += a[i];

        long long mn = cur;

        for (int i = K; i < N; i++) {
            cur += a[i] - a[i - K];
            mn = min(cur, mn);
        }
        cout << mn << endl;
    }
    return 0;
}