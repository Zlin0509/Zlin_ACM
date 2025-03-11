#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// 将区间 [L, R] 分解成若干个 dyadic 区间，返回包含端点的序列（第一个端点为 L，最后一个为 R）。
// 这里的策略是：从当前位置 cur 开始，取最大的 2^k 满足 cur % (2^k) == 0 且 cur + 2^k <= R，然后 cur 变为 cur+2^k。
vector<ll> decompose(ll L, ll R) {
    vector<ll> pts;
    pts.push_back(L);
    ll cur = L;
    while(cur < R) {
        ll p = 1;
        // 尽可能选大，注意：只有当 cur 对 2*p 整除且 cur+p*2 不超过 R 时才能翻倍。
        while ((cur % (p * 2) == 0) && (cur + p * 2 <= R))
            p *= 2;
        cur += p;
        pts.push_back(cur);
    }
    return pts;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // 对 x 方向和 y 方向分别做 dyadic 分解
        vector<ll> X = decompose(l1, r1);
        vector<ll> Y = decompose(l2, r2);
        ll ans = 0;
        // 枚举 x 分解得到的每个区间
        for (size_t i = 0; i + 1 < X.size(); i++){
            ll dx = X[i+1] - X[i];
            // 枚举 y 分解得到的每个区间
            for (size_t j = 0; j + 1 < Y.size(); j++){
                ll dy = Y[j+1] - Y[j];
                if(dx == dy)
                    ans += 1;
                else if(dx < dy)
                    ans += (dy / dx);
                else // dx > dy
                    ans += (dx / dy);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}