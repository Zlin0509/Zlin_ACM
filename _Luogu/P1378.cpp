#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const double pi = 3.1415926535;

int n;
double xa, ya, xb, yb;
bool used[maxn]{};
double x[maxn]{}, y[maxn]{}, r[maxn]{}, ans;

double find(int i)
{
    double s1 = min(abs(x[i] - xa), abs(x[i] - xb));
    double s2 = min(abs(y[i] - ya), abs(y[i] - yb));
    double s = min(s1, s2);
    for (int j = 1; j <= n; j++)
    {
        if(i!=j&&used[j])
        {
            double R = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            s = min(s, max(R - r[j], 0.0));
        }
    }
    return s;
}

void dfs(int k, double sum)
{
    if(k>n)
    {
        ans = max(ans, sum);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!used[i])
        {
            r[i] = find(i);
            used[i] = 1;
            dfs(k + 1, sum + r[i] * r[i] * pi);
            used[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> xa >> ya >> xb >> yb;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    dfs(1, 0.0);
    cout << int(abs(xa - xb) * abs(ya - yb) - ans + 0.5) << '\n';
}