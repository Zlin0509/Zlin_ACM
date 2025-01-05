#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long m1, m2;
    long long as;
    for (int i = 0; i < n; i++)
    {
        cin >> m1 >> m2;
        if (m1 == 1)
        {
            as = m2 * m2;
        }
        else
        {
            as = m1 * m2;
            as /= gcd(m1, m2);
            if (as == m2) as = as * m2 / m1;
        }
        cout << as << endl;
    }
}
