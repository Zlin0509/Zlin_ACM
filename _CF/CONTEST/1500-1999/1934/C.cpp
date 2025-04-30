#include<bits/stdc++.h>
using namespace std;

int n,m;

int ask(int x,int y)
{
    if(x<=0||x>n||y<=0||y>m)
    {
        return -1;
    }
    int z;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>z;
    return z;
}

void solve()
{
    cin>>n>>m;
    auto query = [&](int x, int y){
        if (x < 1 || x > n || y < 1 || y > m)
            return -1;
        cout << "? " << x << ' ' << y << endl;
        int z;
        cin >> z;
        return z;
    };
    int d = query(1, 1);
    int lx = max(1, 2 + d - m);
    int p = query(lx, 2 + d - lx);
    int rx = max(1, 2 + d - n);
    int q = query(2 + d - rx, rx);
    if (query(lx + p / 2, 2 + d - lx - p / 2) == 0){
        cout << "! " << lx + p / 2 << " " <<  2 + d - lx - p / 2<<endl;
    }else{
        cout << "! " << 2 + d - rx - q / 2 << " " << rx + q / 2 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}