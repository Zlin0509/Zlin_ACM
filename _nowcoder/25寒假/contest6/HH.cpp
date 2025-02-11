#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        bool hasEvenDiff = false; // (r-l) even，即子区间长度为 odd
        bool hasOddDiff  = false; // (r-l) odd，即子区间长度为 even
        vector<tuple<int,int,int>> restrictions;
        restrictions.reserve(m);

        for(int i = 0; i < m; i++){
            int l, r, c;
            cin >> l >> r >> c;
            restrictions.push_back({l, r, c});
            int diff = r - l;
            if(diff % 2 == 0) hasEvenDiff = true;
            else hasOddDiff = true;
        }

        if(hasOddDiff && !hasEvenDiff){
            for (int i = n; i >= 1; i--){
                cout << i << (i==1 ? "\n" : " ");
            }
            continue;
        }

        int lenX = n - 1;
        vector<vector<int>> xorGraph(lenX);

        vector<int> forced(lenX, -1);
        vector<pair<int,int>> nonMedianConstraints;

        bool possible = true;

        for(auto &res : restrictions){
            int l, r, c;
            tie(l, r, c) = res;
            if(c == l){
                int idx = l - 1; // X[idx] 对应 X_l (1-indexed)
                if(idx < 0 || idx >= lenX){ possible = false; break; }
                if(forced[idx] == 0){ possible = false; break; }
                forced[idx] = 1;
            }
            else if(c == r){
                // 当 c == r，只能利用左侧比较，即要求 X_{r-1} = 1.
                int idx = r - 2; // X[r-2] 对应 X_{r-1}
                if(idx < 0 || idx >= lenX){ possible = false; break; }
                if(forced[idx] == 0){ possible = false; break; }
                forced[idx] = 1;
            }
            else{ // l < c < r
                int leftGap = c - l;
                int rightGap = r - c;
                if(leftGap == rightGap){
                    // 中位限制：要求 X_{c-1} XOR X_c = 1.
                    // 0-index下：对应 X[c-2] 和 X[c-1].
                    int i1 = c - 2, i2 = c - 1;
                    if(i1 < 0 || i1 >= lenX || i2 < 0 || i2 >= lenX){
                        possible = false; break;
                    }
                    xorGraph[i1].push_back(i2);
                    xorGraph[i2].push_back(i1);
                } else {
                    // 非中位限制：要求 (X_{c-1} OR X_c)==1,
                    // 0-index下对应 X[c-2] OR X[c-1] == 1.
                    int i1 = c - 2, i2 = c - 1;
                    if(i1 < 0 || i1 >= lenX || i2 < 0 || i2 >= lenX){
                        possible = false; break;
                    }
                    nonMedianConstraints.push_back({i1, i2});
                }
            }
        }

        if(!possible){
            cout << -1 << "\n";
            continue;
        }

        vector<int> X(lenX, -1); // -1 表示未赋值
        vector<bool> visited(lenX, false);

        function<void(int,int)> dfs = [&](int u, int val) -> void {
            X[u] = val;
            visited[u] = true;
            // 如果 u 被强制，检查一致性
            if(forced[u] != -1 && forced[u] != val){
                possible = false;
                return;
            }
            for(int v : xorGraph[u]){
                if(!visited[v]){
                    dfs(v, 1 - val);
                    if(!possible) return;
                } else {
                    if(X[v] == val){
                        possible = false;
                        return;
                    }
                }
            }
        };

        for(int i = 0; i < lenX; i++){
            if(!visited[i]){
                int startVal = (forced[i] != -1 ? forced[i] : 1);
                dfs(i, startVal);
                if(!possible) break;
            }
        }

        if(!possible){
            cout << -1 << "\n";
            continue;
        }

        for(int i = 0; i < lenX; i++){
            if(X[i] == -1) X[i] = 1;
            if(forced[i] != -1) X[i] = forced[i];
        }

        for(auto &pr : nonMedianConstraints){
            int i1 = pr.first, i2 = pr.second;
            if(X[i1] == 0 && X[i2] == 0){
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << -1 << "\n";
            continue;
        }

        string s;
        s.resize(lenX);
        for(int i = 0; i < lenX; i++){
            s[i] = (X[i] == 1 ? 'D' : 'I');
        }

        vector<int> perm;
        perm.reserve(n);
        stack<int> st;
        for(int i = 0; i <= n; i++){
            st.push(i+1);
            if(i == n-1 || (i < n-1 && s[i]=='I')){
                while(!st.empty()){
                    perm.push_back(st.top());
                    st.pop();
                }
            }
        }

        for(int i = 0; i < n; i++){
            cout << perm[i] << (i==n-1 ? "\n" : " ");
        }
    }
    return 0;
}