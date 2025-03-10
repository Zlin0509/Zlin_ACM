//
// Created by 27682 on 2024/12/25.
//

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

typedef double db;

const db PI = acos(-1.0);
constexpr db EPS = 1e-3;

struct Point
{
    db x, y;
} P[3];

db len[3], c = 0, a[3];

db dis(int i, int j)
{
    return sqrt((P[i].x - P[j].x) * (P[i].x - P[j].x) + (P[i].y - P[j].y) * (P[i].y - P[j].y));
}

db gcd(db a, db b)
{
    while (fabs(b) > EPS)
    {
        db temp = b;
        b = fmod(a, b);
        a = temp;
    }
    return a;
}

inline void Zlin()
{
    for (int i = 0; i < 3; i++)
        cin >> P[i].x >> P[i].y;
    for (int i = 0; i < 3; i++)
    {
        len[i] = dis(i, (i + 1) % 3);
        c += len[i];
    }
    c /= 2;
    db A = sqrt(c * (c - len[0]) * (c - len[1]) * (c - len[2]));
    db r = len[0] * len[1] * len[2] / (4 * A);
    for (int i = 0; i < 2; i++)
    {
        a[i] = acos((max(-1.0,min(1.0,1 - len[i] * len[i] / (2 * r * r)))));
    }
    a[2] = 2 * PI - a[0] - a[1];
    db t = gcd(a[0], gcd(a[1], a[2]));
    cout << fixed << setprecision(9) << PI * r * r * sin(t) / t << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
