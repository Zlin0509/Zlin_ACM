#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        // 读取网格
        vector<vector<int>> grid(n, vector<int>(m));
        int maxColor = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
                maxColor = max(maxColor, grid[i][j]);
            }
        }
        
        // cost[color] 表示颜色 color 的代价
        // 如果该颜色只出现在彼此互不相邻的孤立单元格中，则代价为1；
        // 如果存在任意两个相邻（共享边）的同色单元格，则代价为2。
        // 初始值0表示该颜色还未出现过。
        vector<int> cost(maxColor + 1, 0);
 
        // 遍历网格，检查每个单元格与右边和下边的单元格是否同色
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int col = grid[i][j];
                // 标记颜色已出现，初始代价为1
                if(cost[col] == 0)
                    cost[col] = 1;
                // 检查右边
                if(j + 1 < m && grid[i][j+1] == col)
                    cost[col] = 2;
                // 检查下边
                if(i + 1 < n && grid[i+1][j] == col)
                    cost[col] = 2;
            }
        }
 
        // 计算所有出现过的颜色的总代价 T 以及最大代价 M
        long long totalCost = 0;
        int best = 0;
        for (int c = 1; c <= maxColor; c++){
            if(cost[c] != 0){
                totalCost += cost[c];
                best = max(best, cost[c]);
            }
        }
 
        // 最终答案：总代价减去最终颜色的代价
        cout << totalCost - best << "\n";
    }
    
    return 0;
}
