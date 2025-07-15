//
// Created by Zlin on 2025/2/8.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool check_win(const vector<string>& board, char player)
{
    // 检查行、列、对角线是否有三个相同的棋子
    // 行
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // 列
    for (int j = 0; j < 3; ++j)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // 对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool can_win_in_three_moves(vector<string>& board)
{
    // 模拟小L的连续两步
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 'G')
            {
                board[i][j] = 'X'; // 小L的第一步
                if (check_win(board, 'X'))
                    return true;
                // 第二步
                for (int k = 0; k < 3; ++k)
                {
                    for (int l = 0; l < 3; ++l)
                    {
                        if (board[k][l] == 'G')
                        {
                            board[k][l] = 'X'; // 小L的第二步
                            if (check_win(board, 'X'))
                                return true;
                            // 炸鸡下棋
                            for (int m = 0; m < 3; ++m)
                            {
                                bool check = false;
                                for (int n = 0; n < 3; ++n)
                                {
                                    if (board[m][n] == 'G')
                                    {
                                        board[m][n] = 'O'; // 炸鸡的下子
                                        check = check_win(board, 'O');
                                        // 检查小L的第三步
                                        if (!check)
                                            for (int p = 0; p < 3; ++p)
                                            {
                                                for (int q = 0; q < 3; ++q)
                                                {
                                                    if (board[p][q] == 'G')
                                                    {
                                                        board[p][q] = 'X'; // 小L的第三步
                                                        if (check_win(board, 'X'))
                                                        {
                                                            board[i][j] = 'G'; // 回退
                                                            board[k][l] = 'G'; // 回退
                                                            board[m][n] = 'G'; // 回退
                                                            board[p][q] = 'G'; // 回退
                                                            return true;
                                                        }
                                                        board[p][q] = 'G'; // 回退
                                                    }
                                                }
                                            }
                                        board[m][n] = 'G'; // 回退
                                        if (check)
                                            break;
                                    }
                                }
                                if (check)
                                    break;
                            }
                            board[k][l] = 'G'; // 回退
                        }
                    }
                }
                board[i][j] = 'G'; // 回退
            }
        }
    }
    return false;
}

inline void Zlin()
{
    vector<string> board(3);
    for (int i = 0; i < 3; ++i)
        cin >> board[i];

    // 检查是否能通过连续两步棋在炸鸡下子后胜利
    if (can_win_in_three_moves(board))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
