#include <bits/stdc++.h>
using namespace std;

// 预处理数组：
// fullFreq[c][i]：字母 c 在 s[1..i] 中出现次数（1-indexed）
// Lfreq[c][i]：字母 c 在 s[1..half]（左半边）中出现次数
// Rfreq[c][i]：字母 c 在 T[1..i] 中出现次数，其中 T[i] = s[n - i + 1]（即左半边对应的右侧镜像序列）
// P_diff[i]：对于 i=1..half，P_diff[i] = # of j=1..i 使得 s[j]!= s[n-j+1]

struct Precomp {
    int n, half;
    vector<vector<int>> fullFreq; // size: 26 x (n+1)
    vector<vector<int>> Lfreq;    // 26 x (half+1)
    vector<vector<int>> Rfreq;    // 26 x (half+1)
    vector<int> P_diff;           // size: half+1
};

Precomp buildPrecomp(const string &s) {
    Precomp pc;
    pc.n = s.size();
    pc.half = pc.n / 2;
    int n = pc.n, half = pc.half;
    pc.fullFreq.assign(26, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++){
        int ch = s[i-1] - 'a';
        for (int c = 0; c < 26; c++){
            pc.fullFreq[c][i] = pc.fullFreq[c][i-1];
        }
        pc.fullFreq[ch][i]++;
    }
    // 左半边
    pc.Lfreq.assign(26, vector<int>(half+1, 0));
    for (int i = 1; i <= half; i++){
        int ch = s[i-1] - 'a';
        for (int c = 0; c < 26; c++){
            pc.Lfreq[c][i] = pc.Lfreq[c][i-1];
        }
        pc.Lfreq[ch][i]++;
    }
    // 右侧镜像序列 T：T[i] = s[n-i] (对应 s[n-i+1] 1-indexed)
    pc.Rfreq.assign(26, vector<int>(half+1, 0));
    for (int i = 1; i <= half; i++){
        int ch = s[n-i] - 'a';
        for (int c = 0; c < 26; c++){
            pc.Rfreq[c][i] = pc.Rfreq[c][i-1];
        }
        pc.Rfreq[ch][i]++;
    }
    // P_diff
    pc.P_diff.resize(half+1, 0);
    pc.P_diff[0] = 0;
    for (int i = 1; i <= half; i++){
        int diff = (s[i-1] != s[n-i]) ? 1 : 0;
        pc.P_diff[i] = pc.P_diff[i-1] + diff;
    }
    return pc;
}

// 查询区间 [l, r]（1-indexed）在预处理数组 arr 中的区间和
inline int query(const vector<int>& arr, int l, int r) {
    if(l > r) return 0;
    return arr[r] - arr[l-1];
}

// 查询二维前缀数组 freq[c] 在区间 [l, r]
inline int query2D(const vector<int>& freq, int l, int r) {
    if(l > r) return 0;
    return freq[r] - freq[l-1];
}

// 对于候选区间 Q = [L, R]（1-indexed，整个 s 中的区间），判断能否仅通过对 Q 内字符洗牌得到回文
bool checkCandidate(int L, int R, const string &s, const Precomp &pc) {
    int n = pc.n, half = pc.half;
    //【1】固定部分检测：左半边中哪些镜像对“未触及” Q，必须原本匹配。
    // 定义“触及”分为两部分：
    // I = { i in [1, half] : i in Q } = [L, min(R, half)]（若 L<=min(R,half)）
    int I_l = L, I_r = min(R, half);
    bool hasI = (L <= I_r);
    // J = { i in [1, half] : 对应右侧 j=n-i+1 in Q }
    int J_l = max(1, n - R + 1), J_r = min(half, n - L + 1);
    bool hasJ = (J_l <= J_r);
    // 计算“触及”部分在左半边的 diff 总和
    int sumI = hasI ? query(pc.P_diff, I_l, I_r) : 0;
    int sumJ = hasJ ? query(pc.P_diff, J_l, J_r) : 0;
    // 计算二者交集：I ∩ J = [max(I_l, J_l), min(I_r, J_r)]
    int inter_l = max(I_l, J_l), inter_r = min(I_r, J_r);
    int sumInter = (hasI && hasJ && inter_l <= inter_r) ? query(pc.P_diff, inter_l, inter_r) : 0;
    int touched = sumI + sumJ - sumInter;
    // 固定部分在左半边为所有 i=1..half 不触及 Q，即总 diff 减去 touched 部分
    int fixed_diff = pc.P_diff[half] - touched;
    if(fixed_diff != 0) return false; // 存在固定的镜像对未匹配

    //【2】计算“强制需求”
    // 对于镜像对中：
    // (a) 对于 i 在 I 但不在交集，则固定端为 j = n-i+1，需求 letter = s[j]
    // (b) 对于 i 在 J 但不在交集，则固定端为 i，需求 letter = s[i]
    int forced[26] = {0};
    // 利用预处理的 Rfreq 来统计 (a)
    if(hasI) {
        for (int c = 0; c < 26; c++){
            int cntI = query(pc.Rfreq[c], I_l, I_r);
            int cntInter = 0;
            if(hasI && hasJ && inter_l <= inter_r)
                cntInter = query(pc.Rfreq[c], inter_l, inter_r);
            forced[c] += (cntI - cntInter);
        }
    }
    // 利用预处理的 Lfreq 来统计 (b)
    if(hasJ) {
        for (int c = 0; c < 26; c++){
            int cntJ = query(pc.Lfreq[c], J_l, J_r);
            int cntInter = 0;
            if(hasI && hasJ && inter_l <= inter_r)
                cntInter = query(pc.Lfreq[c], inter_l, inter_r);
            forced[c] += (cntJ - cntInter);
        }
    }

    //【3】查询候选区间 Q = [L,R] 内各字母“可用数”（用全局全前缀数组 fullFreq 查询）
    for (int c = 0; c < 26; c++){
        int avail = pc.fullFreq[c][R] - pc.fullFreq[c][L-1];
        if(avail < forced[c]) return false;
        if((avail - forced[c]) % 2 != 0) return false;
    }
    return true;
}

// 对于一个给定 k（区间长度），判断是否存在某个 Q = [L,R]（R=L+k-1）使得可转为回文
bool canWithLength(int k, const string &s, const Precomp &pc) {
    int n = pc.n;
    // k == 0 时，整个 s 必须已经回文
    if(k == 0) {
        // s 回文当且仅当左半边所有镜像对匹配，即 P_diff[half]==0
        return (pc.P_diff[pc.half] == 0);
    }
    for (int L = 1; L <= n - k + 1; L++){
        int R = L + k - 1;
        if(checkCandidate(L, R, s, pc))
            return true;
    }
    return false;
}

// 主程序：对每个测试用例，利用二分查找最小 k
int solveTestCase(const string &s) {
    Precomp pc = buildPrecomp(s);
    int n = s.size();
    int lo = 0, hi = n, ans = n;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(canWithLength(mid, s, pc)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solveTestCase(s) << "\n";
    }
    return 0;
}
