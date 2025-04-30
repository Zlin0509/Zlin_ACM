#include<bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 200050
#define maxm 200050
#define vi vector <int>
#define vvi vector <vi>
#define endl '\n'
#define ll long long
using namespace std;

int n;
int idg[maxn];
bool tag[maxn];
queue<int> q;

void clean() {
    memset(idg, 0, sizeof(int) * (n + 5));
    memset(tag, false, sizeof(bool) * (n + 5));
}

void solve() {
    cin >> n;
    vi a(n + 1);
    clean();
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        tag[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idg[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (idg[i] == 0) q.push(i);
    }
    vi ans;
    //拓扑排序
    while (q.size()) {
        int x = q.front();
        q.pop();
        int y = a[x];
        idg[y]--;
        if (tag[x]) tag[y] = !tag[y];
        if (idg[y] == 0) q.push(y);
        if (tag[x]) tag[x] = false, ans.emplace_back(x);
    }
    //以下为处理环
    for (int i = 1; i <= n; i++) {
        if (idg[i] && tag[i]) { //在环上且为 1
            vi ansa, ansb;
            int nw = i;
            bool flag = false; //flag 作为交替统计的标记
            do {
                idg[nw]--;
                if (tag[nw]) flag = !flag;
                if (flag) ansa.emplace_back(nw);
                else ansb.emplace_back(nw);
                nw = a[nw];
            } while (idg[nw]);
            if (flag) {
                cout << -1 << endl;
                return;
            }
            if (ansa.size() < ansb.size()) //选择更小的方案加入答案
                ans.insert(ans.end(), ansa.begin(), ansa.end());
            else
                ans.insert(ans.end(), ansb.begin(), ansb.end());
        }
    }
    cout << ans.size() << endl;
    for (int e: ans) cout << e << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}