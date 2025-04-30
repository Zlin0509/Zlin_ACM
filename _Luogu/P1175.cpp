#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

string s;
stack<char> a, b;
stack<int> c, d;

int check(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    if (c == '(')
        return 4;
    return 5;
}

ll cal(ll a, ll b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
    return pow(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            a.push(s[i]);
        else
        {
            if (b.empty())
                b.push(s[i]);
            else
            {
                if (s[i] == ')')
                {
                    while (b.top() != '(')
                    {
                        // cout << b.top() << endl;
                        a.push(b.top());
                        b.pop();
                    }
                    b.pop();
                }
                else if (s[i] == '^')
                {
                    b.push(s[i]);
                }
                else if (!b.empty() && b.top() != '(' && check(s[i]) <= check(b.top()))
                {
                    while (!b.empty() && b.top() != '(' && check(s[i]) <= check(b.top()))
                    {
                        a.push(b.top());
                        b.pop();
                    }
                    b.push(s[i]);
                }
                else
                {
                    b.push(s[i]);
                }
            }
        }
    }
    while (!b.empty())
    {
        a.push(b.top());
        b.pop();
    }

    while (!a.empty())
    {
        b.push(a.top());
        a.pop();
    }

    while (!b.empty())
    {
        cout << b.top() << ' ';
        a.push(b.top());
        b.pop();
    }
    cout << '\n';

    while (!a.empty())
    {
        b.push(a.top());
        a.pop();
    }

    // while (b.size() > 1)
    // {
    //     while (!b.empty())
    //     {
    //         if (isdigit(b.top()))
    //         {
    //             c.push(b.top() - '0');
    //             b.pop();
    //         }
    //         else
    //         {
    //             int x, y;
    //             x = c.top();
    //             c.pop();
    //             y = c.top();
    //             c.pop();
    //             c.push(cal(y, x, b.top()));
    //             b.pop();
    //             break;
    //         }
    //     }

    //     while (!c.empty())
    //     {
    //         b.push(c.top());
    //         c.pop();
    //     }

    //     while (!b.empty())
    //     {
    //         a.push(b.top());
    //         b.pop();
    //     }

    //     while (!a.empty())
    //     {
    //         b.push(a.top());
    //         a.pop();
    //     }

    //     while (!b.empty())
    //     {
    //         cout << b.top();
    //         a.push(b.top());
    //         b.pop();
    //     }

    //     while (!a.empty())
    //     {
    //         b.push(a.top());
    //         a.pop();
    //     }
    // }
    while (!b.empty())
    {
        if (isdigit(b.top()))
        {
            c.push(b.top() - '0');
            b.pop();
        }
        else
        {
            int x, y;
            x = c.top();
            c.pop();
            y = c.top();
            c.pop();
            c.push(cal(y, x, b.top()));
            b.pop();

            while (!c.empty())
            {
                d.push(c.top());
                c.pop();
            }

            while (!d.empty())
            {
                cout << d.top() << ' ';
                c.push(d.top());
                d.pop();
            }

            while (!b.empty())
            {
                cout << b.top() << ' ';
                a.push(b.top());
                b.pop();
            }

            while (!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
            cout << '\n';
        }
    }
}