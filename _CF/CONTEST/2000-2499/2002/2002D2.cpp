#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define per(i,a,n) for(int i=(n);i>=(a);--i)
#define SZ(x) ((int)(x).size())

using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=3e5+10;

int n,q,fa[maxn],p[maxn],dfn[maxn],idx,sz[maxn],res;
vector<int> e[maxn];

inline void dfs(int u){
    sz[u]=1; dfn[u]=++idx;
    for(auto v:e[u]) dfs(v),sz[u]+=sz[v];
}

inline void init(){
    idx=res=0;
    rep(i,1,n) e[i].clear();
}

inline int calc(int i){
    if(i==1 || i>n) return 0;
    int u=p[i-1],v=p[i];
    return (dfn[u]>=dfn[fa[v]]&&dfn[u]<=dfn[fa[v]]+sz[fa[v]]-1);
}

inline void solve(){
    scanf("%d%d",&n,&q);
    init();
    rep(i,2,n) scanf("%d",&fa[i]),e[fa[i]].push_back(i);
    rep(i,1,n) scanf("%d",&p[i]);
    dfs(1);
    rep(i,2,n) res+=calc(i);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        set<int> st;
        st.insert(x); st.insert(x+1); st.insert(y); st.insert(y+1);
        for(auto i:st) res-=calc(i);
        swap(p[x],p[y]);
        for(auto i:st) res+=calc(i);
        puts(res==n-1?"YES":"NO");
    }
}

signed main(){
    int _=1;
    scanf("%d",&_);
    while(_--) solve();
}