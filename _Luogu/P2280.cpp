#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s[5010][5010];
// ��Ϊ�ռ��Ϊ���ţ�����ֻ����һ�����飬�����ǰ׺�ͺ�ԭ����ֱ�ӱ�����

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        s[x + 1][y + 1] += v; // ���������궼��һ�����귶Χ��� [1, 5001]������Խ��
    }

    int N = 5001; // N Ϊ���귶Χ
                  // ����һ
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    /*
        // ������
        for (int i = 1; i <= N; i ++)
            for (int j = 1; j <= N; j ++) s[i][j] += s[i][j - 1];
        for (int j = 1; j <= N; j ++)
            for (int i = 1; i <= N; i ++) s[i][j] += s[i - 1][j];
        */

    int ans = 0;
    for (int i = m; i <= N; i++)
        for (int j = m; j <= N; j++)
        {
            int num = s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m];
            // num Ϊ�� (i, j) Ϊ���½ǵı߳�Ϊ m �������������е�Ŀ���ֵ֮��
            ans = max(ans, num);
            // �� num ���´�
        }

    cout << ans << endl;

    return 0;
}