#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using ull =unsigned long long;
const int N=1e3+5;
const int M=21;
const ll inf=1e18;
const ll mod=998244353;
ll dp[N][N];
ll n,c[N],mp[N];
vector <ll>g[N];
void dfs(ll x) {
    for (auto v : g[x]) {
        dfs(v);
    }
    if (c[x]) {
        dp[x][c[x]]=1;
    }else {
        for (int j=1;j<=n;j++) dp[x][j]=dp[g[x][0]][j];
        for (auto v : g[x]) {
            if (v==g[x][0]) continue;
            ll mnv=inf,mnx=inf;
            for (int j=1;j<=n;j++) {
                if (~dp[v][j])mnv=min(mnv,dp[v][j]);
                if (~dp[x][j])mnx=min(mnx,dp[x][j]);
            }
            for (int j=1;j<=n;j++) {
                if (~dp[x][j]) {
                    if (~dp[v][j]) {
                        dp[x][j]=min(dp[x][j]+min(mnv,dp[v][j]-1),dp[v][j]+min(mnx,dp[x][j]-1));
                    }else {
                        dp[x][j]=min(dp[x][j],mnx+1)+mnv;
                    }
                }else {
                    if (~dp[v][j]) {
                        dp[x][j]=min(dp[v][j],mnv+1)+mnx;
                    }
                }
            }
        }
    }
}
void solve(){
    cin >> n;
    for (int i=2;i<=n;i++) {
        ll x; cin >> x;
        g[x].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        cin >> c[i];
    }
    memset(dp,-1,sizeof(dp));
    if (n>=N) while (1);
    dfs(1);
    ll ans=inf;
    for (int i=1;i<=n;i++) {
        if (~dp[1][i]) ans=min(ans,dp[1][i]);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _=1;  //cin >> _;
    while(_--) solve();
    return 0;
}