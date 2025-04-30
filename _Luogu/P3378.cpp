#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

priority_queue<int, vector<int>, greater<int>> a;
int n, op, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            a.push(x);
        }
        else if (op == 2)
            cout << a.top() << '\n';
        else
            a.pop();
    }
}