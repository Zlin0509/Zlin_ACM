#include <bits/stdc++.h>
using namespace std;

/*
  Problem: 给定长度为 n 的字符串 s（仅由小写字母组成），和一个正整数 k。
  定义：s 是 k-fold string 当且仅当 s = t^k，即某字符串 t 重复 k 次拼接。
  询问 q 次，每次给出区间 [x,y]，计算有多少对 (l,r) 满足 x <= l <= r <= y，
  且子串 s[l..r] 的字符可以重排后变成一个 k-fold string。

  解决思路要点：
    - 维护前缀哈希 prefix_sig[i] 表示 s[1..i] 的“频次 mod k 向量”对应的 64 位哈希。
    - 对所有 prefix_sig[0..n] 离散化，得到 sig_id[i]。
    - 使用 Mo 算法离线处理，每次把前缀下标纳入/移除时，更新当前答案 cur_ans。
    - 排序时注意避免 lambda 形参名与全局分块大小 B 冲突。
*/

using ull = unsigned long long;
using ll  = long long;

static const int MAXN = 300000 + 5;
static const int MAXQ = 300000 + 5;

// 预先给 26 个字母各分配一个 64 位常数
static const ull RND[26] = {
    0x9e3779b97f4a7c15ULL, 0xC13FA9A902A6328FULL, 0x91E10DA5C79E7B1DULL, 0xD3DF07BFBA429CD9ULL,
    0xA4093822299F31D0ULL, 0x08979F2DD921B92BULL, 0x7F4A7C15F39CC060ULL, 0x429CDFD13D9FE172ULL,
    0x99F31D091AD7D6AEULL, 0xD92A6B3CB81615C5ULL, 0xB14CDD9C31C66F1EULL, 0x74CA1AF8C53D1A1DULL,
    0xC1D9B379483C6871ULL, 0x48B26CC3B4F61DD5ULL, 0x9DA9AE47BF39F9D5ULL, 0x2C3AF5E6758A6FA5ULL,
    0xE7FAD3C6517A4CDDULL, 0x1A2C3B4D5E6F7801ULL, 0xF39CC5E7A9B0D172ULL, 0x8A5D7E19B3C4E6A2ULL,
    0xBB99DD77FFAA3311ULL, 0xEE11223344556677ULL, 0xA55AA55AA55AA55AULL, 0xC0FFEE1234567890ULL,
    0x1234567890ABCDEFULL, 0xFEDCBA0987654321ULL
};

int n, k, q;
char s[MAXN];
ull prefix_sig[MAXN];
int cnt_mod[26];

ull all_sig[MAXN];
int sig_id[MAXN];
int tot_sig;

struct Query {
    int l, r, id;
};
int B;
Query qu[MAXQ];
ll answers[MAXQ];

ll cur_ans;
int curL, curR;
int cnt_id[MAXN];

inline void add_pos(int pos) {
    int id = sig_id[pos];
    ll old = cnt_id[id];
    cur_ans -= old * (old - 1LL) / 2;
    cnt_id[id]++;
    ll ne = cnt_id[id];
    cur_ans += ne * (ne - 1LL) / 2;
}

inline void del_pos(int pos) {
    int id = sig_id[pos];
    ll old = cnt_id[id];
    cur_ans -= old * (old - 1LL) / 2;
    cnt_id[id]--;
    ll ne = cnt_id[id];
    cur_ans += ne * (ne - 1LL) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    // 构造前缀哈希
    prefix_sig[0] = 0ULL;
    memset(cnt_mod, 0, sizeof(cnt_mod));
    for (int i = 1; i <= n; i++) {
        int ch = s[i] - 'a';
        int old_mod = cnt_mod[ch];
        int new_mod = (old_mod + 1) % k;
        cnt_mod[ch] = new_mod;
        int diff = new_mod - old_mod;  // +1 或 -(k-1)
        prefix_sig[i] = prefix_sig[i - 1] + (ull)diff * RND[ch];
    }

    // 离散化 prefix_sig[0..n]
    for (int i = 0; i <= n; i++) {
        all_sig[i] = prefix_sig[i];
    }
    sort(all_sig, all_sig + (n + 1));
    tot_sig = 0;
    for (int i = 0; i <= n; i++) {
        if (i == 0 || all_sig[i] != all_sig[i - 1]) {
            all_sig[tot_sig++] = all_sig[i];
        }
    }
    for (int i = 0; i <= n; i++) {
        sig_id[i] = int(lower_bound(all_sig, all_sig + tot_sig, prefix_sig[i]) - all_sig);
    }

    // 读入查询，转化为前缀区间 [l-1, r]
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qu[i].l  = l - 1;
        qu[i].r  = r;
        qu[i].id = i;
    }

    // 计算 Mo 分块大小
    B = max(1, int(n / sqrt(double(q))));

    // 排序：注意形参不要用 B，避免与外部块大小冲突
    sort(qu, qu + q, [&](const Query &A, const Query &C) {
        int blockA = A.l / B;
        int blockC = C.l / B;
        if (blockA != blockC) return blockA < blockC;
        if ((blockA & 1) == 0) return A.r < C.r;
        else                   return A.r > C.r;
    });

    // Mo 扫描初始化
    curL = 0;
    curR = -1;
    cur_ans = 0;
    memset(cnt_id, 0, sizeof(int) * tot_sig);

    for (int i = 0; i < q; i++) {
        int L = qu[i].l;
        int R = qu[i].r;
        while (curL > L)   add_pos(--curL);
        while (curR < R)   add_pos(++curR);
        while (curL < L)   del_pos(curL++);
        while (curR > R)   del_pos(curR--);
        answers[qu[i].id] = cur_ans;
    }

    ostringstream oss;
    for (int i = 0; i < q; i++) {
        oss << answers[i] << "\n";
    }
    cout << oss.str();
    return 0;
}
