#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> a;
int main()
{
    int b, c, d, e = 1, f = 0;
    cin >> b >> c;
    for (int i = 1; i <= b; i++)
    {
        a.push(i); // 模拟队列
    }
    while (!a.empty())
    {
        if (e == c) // 如果这个人正好被踢
        {
            cout << a.front() << " "; // 先输出
            a.pop();                  // 再删除
            e = 1;                    // 再从1开始报数
        }
        else if (e != c) // 如果不被剔除
        {
            e++;               // 报的数+1
            a.push(a.front()); // 先把head压进队尾
            a.pop();           // 再把head删除
        }
    }
    return 0; // 结束程序（完美）
}