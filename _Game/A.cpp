#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<ll> xs(n), ys(n);
        ll sumx = 0, sumy = 0;
        ll xmin = LLONG_MAX, xmax = LLONG_MIN;
        ll ymin = LLONG_MAX, ymax = LLONG_MIN;
        unordered_map<ll,int> diag;
        diag.reserve(n*2);

        for(int i = 0; i < n; i++){
            ll x,y;
            cin >> x >> y;
            xs[i]=x; ys[i]=y;
            sumx += x;
            sumy += y;
            xmin = min(xmin, x);
            xmax = max(xmax, x);
            ymin = min(ymin, y);
            ymax = max(ymax, y);
            diag[x+y] ^= 1;  // 只要对同一个 u 异或，就能记下奇偶
        }

        // 1) 找出唯一奇数次的主对角线 u* = s+t
        ll u_star = 0;
        for(auto &kv : diag){
            if(kv.second & 1){
                u_star = kv.first;
                break;
            }
        }

        // 2) s mod2, t mod2
        int px = (sumx & 1);
        int py = (sumy & 1);

        // 先算出 k=0 时的「中心」解
        // 设 D ≡ (s - t) mod2 = px - py (mod2)
        int D = (px - py + 2) & 1;
        ll s0 = (u_star + D) / 2;
        ll t0 = u_star - s0;  // 保证 s0 + t0 = u_star

        // 令 k_min ≤ k ≤ k_max，确保 (s,t) 落在包围盒内：
        //   xmin ≤ s0 + k ≤ xmax   ⇒  k ∈ [xmin-s0, xmax-s0]
        //   ymin ≤ t0 - k ≤ ymax   ⇒  k ∈ [t0-ymax, t0-ymin]
        ll k1 = xmin - s0;
        ll k2 = xmax - s0;
        ll k3 = t0 - ymax;
        ll k4 = t0 - ymin;
        ll kmin = max(k1, k3);
        ll kmax = min(k2, k4);

        // 题目保证至少一个解，区间非空
        ll k = kmin;

        ll s = s0 + k;
        ll t = t0 - k;
        cout << s << " " << t << "\n";
    }
    return 0;
}
