             #include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N=1e6+5;
const int M=1e6+5;
const ll inf=1e18;
const ll mod=26;
ll n,m,k;
string s[301];
string ss="abcdefghijklmnopqrstuvwxyz";
void solve(){
    cin >> n >> m >> k;
    if(m>k){
        cout << "No\n";
        return;
    }
    if(m==0){
        if(n>26){
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                char c='a'+i-1;
                cout << c;
            }
            cout << "\n";
        }
        return;
    }
    ll cnt=0,id=0;
    vector <string> v;
    while(v.size()<n){
        ll len=26;
        char c='a'+id%26;
        // cout << id << "\n";
        for(int ii=0;ii<len-id;ii++){
            string t;
            for(int i=1;i<=m;i++){
                t+=c;
            }
            char cc=ii+'a';
            for(int i=1;i<=k-m;i++){
                if(i&1){
                    t+=cc;
                }else{
                    t+=ss[(id+ii)%26];
                }
            }
            if(ii!=id) v.push_back(t);
            if(v.size()==n) break;
        }
        id++;
    }
    cout << "Yes\n";
    for(auto o : v) cout << o << "\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _=1;// cin >> _;
    while(_--) solve();
    return 0;
}