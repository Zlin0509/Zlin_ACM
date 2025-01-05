#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, a[101];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x % 3 == 0 ? a[i] = 0 : a[i] = 1;
        //TODO
    }
    for (int i = 0; i < n; i++)
    {
        a[i] == 0 ? cout << "Second" : cout << "First";
        if (i != n - 1)
        {
            cout << endl;
            //TODO
        }
    }
}
