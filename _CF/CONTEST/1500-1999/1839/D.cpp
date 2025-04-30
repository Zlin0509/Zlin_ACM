// LUOGU_RID: 112012510
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

int T, n;
#define N 510
int a[N];
int dp[N][N];
bool f[N][N];

void ckmin(int &x, int y) { x = x < y ? x : y; }

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int l = 1; l <= n; l++) {
            f[l][l] = 1;
            for (int r = l + 1; r <= n; r++)
                f[l][r] = f[l][r - 1] & (a[r - 1] < a[r]);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            dp[i][0] = f[1][i] ? 0 : 0x3f3f3f3f;
        for (int k = 1; k <= n; k++) {
            dp[0][k] = 0;
            for (int i = 1; i <= n; i++) {
                dp[i][k] = dp[i][k - 1];
                if (a[i - 1] < a[i])
                    ckmin(dp[i][k], dp[i - 1][k]);
                for (int j = 0; j < i - 1; j++)
                    if (a[j] < a[i])
                        ckmin(dp[i][k], dp[j][k - 1] + i - 1 - j);
                // printf("dp[%d][%d] = %d\n", i, k, dp[i][k]);
            }
        }
        for (int k = 1; k <= n; k++) {
            int ans = dp[n][k];
            for (int i = 1; i < n; i++)
                ckmin(ans, dp[i][k - 1] + n - i);
            printf("%d ", ans);
        }
        putchar('\n');
    }
    return 0;
}