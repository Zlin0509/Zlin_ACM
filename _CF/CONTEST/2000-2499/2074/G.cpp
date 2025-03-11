#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// 本题中 n<=400，总体 O(n^3) 可行
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        // 方案1：单个三角形（任取 3 个顶点）的最大乘积
        long long bestSingle = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                for (int k = j+1; k < n; k++){
                    long long prod = (long long)a[i] * a[j] * a[k];
                    bestSingle = max(bestSingle, prod);
                }
            }
        }

        // 为了枚举圆上连续区间，我们构造 b 数组：b[i] = a[i mod n]，长度为 2*n
        int N = 2 * n;
        vector<int> b(N);
        for (int i = 0; i < N; i++){
            b[i] = a[i % n];
        }

        // dp[i][j] 表示区间 [i, j]（在 b 数组上）的方案——要求区间内所有顶点都被划分成三角形，且区间长度必为 3 的倍数
        // 不合法状态记为 -INF
        const long long NEG_INF = -1000000000000000000LL; //一个足够小的数
        vector<vector<long long>> dp(N, vector<long long>(N, NEG_INF));

        // 空区间（i>j）视为 0 ——这里后面用到时用条件判断
        // 基础：区间长度为 3 的情况
        for (int i = 0; i + 3 - 1 < N; i++){
            int j = i + 3 - 1;
            dp[i][j] = (long long) b[i] * b[i+1] * b[j];
        }

        // 枚举区间长度 L（要求 L 为 3 的倍数，从 6 开始，最大不超过 n）
        for (int L = 6; L <= n; L += 3){
            for (int i = 0; i + L - 1 < N; i++){
                int j = i + L - 1;
                // 方案一：区间分割
                for (int m = i; m < j; m++){
                    if(dp[i][m] != NEG_INF && dp[m+1][j] != NEG_INF){
                        dp[i][j] = max(dp[i][j], dp[i][m] + dp[m+1][j]);
                    }
                }
                // 方案二：取“耳”
                for (int k = i+1; k < j; k++){
                    long long left = 0, right = 0;
                    if(i+1 <= k-1){
                        if(dp[i+1][k-1] == NEG_INF) continue;
                        left = dp[i+1][k-1];
                    }
                    if(k+1 <= j-1){
                        if(dp[k+1][j-1] == NEG_INF) continue;
                        right = dp[k+1][j-1];
                    }
                    long long candidate = (long long) b[i] * b[k] * b[j] + left + right;
                    dp[i][j] = max(dp[i][j], candidate);
                }
            }
        }

        // 枚举 b 数组中所有“合法”区间（长度为 L，L 为 3 的倍数，且 L <= n，即区间中顶点在圆上连续）
        long long bestMultiple = 0;
        for (int L = 3; L <= n; L += 3){
            for (int i = 0; i + L - 1 < N; i++){
                int j = i + L - 1;
                if(L <= n && dp[i][j] != NEG_INF){
                    bestMultiple = max(bestMultiple, dp[i][j]);
                }
            }
        }

        long long ans = max(bestSingle, bestMultiple);
        cout << ans << "\n";
    }
    return 0;
}
