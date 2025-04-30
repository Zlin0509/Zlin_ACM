#include<bits/stdc++.h>

int main()
{
    char n1[100];
    int a[100], c[100], lena, i, x = 0, lenc, b;

    std::memset(a, 0, sizeof(a));
    std::memset(c, 0, sizeof(c));

    std::cin >> n1 >> b;
    lena = strlen(n1);

    for (i = 1; i <= lena; i++)
    {
        a[i] = n1[i - 1] - '0'; // 除法不需要逆序存放
    }

    //-------------------------初始化------------------------------

    for (i = 1; i <= lena; i++)
    {
        c[i] = (a[i] + x * 10) / b; // 算上上一位剩下的继续除
        x = (a[i] + 10 * x) % b;    // 求余
    }

    lenc = 1;
    while (c[lenc] == 0 && lenc < lena)
    {
        lenc++;
    }

    for (i = lenc; i < lena; i++)
        std::cout << c[i];

    return 0;
}