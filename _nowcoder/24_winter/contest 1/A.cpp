#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 计算两个数的最小公倍数
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

// 计算多个数的最小公倍数
long long lcm_multiple(const vector<long long>& nums)
{
    long long result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
        result = lcm(result, nums[i]);
        if (result > 1e18)
        {
            return 1e18 + 1; // 如果超过 10^18，就直接返回一个超过 10^18 的数
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t; // 读取测试组数
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        bool tag = false;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] == 1)
                tag = true;
        }
        if (tag)
        {
            cout << -1 << endl;
            continue;
        }

        long long lcm_val = lcm_multiple(a);
        if (lcm_val > 1e18)
        {
            cout << 1e18 + 1 << endl;
        }
        else
        {
            cout << lcm_val + 1 << endl;
        }
    }

    return 0;
}
