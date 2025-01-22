#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path) {
    visited[node] = true;
    path.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, path);
        }
    }
}

void find_hamiltonian_path(int n, const vector<vector<int>>& adj) {
    vector<int> degree(n + 1, 0);

    // 统计每个节点的度数
    for (int i = 1; i <= n; ++i) {
        degree[i] = adj[i].size();
    }

    // 统计度数为1的节点数量
    int leaf_count = 0;
    int start_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            leaf_count++;
            start_node = i;
        }
    }

    if (leaf_count > 2) {
        cout << -1 << endl;
        return;
    }

    // 从一个叶子节点开始进行DFS找哈密顿路径
    vector<int> path;
    vector<bool> visited(n + 1, false);

    dfs(start_node, adj, visited, path);

    // 检查路径长度是否等于 n
    if (path.size() == n) {
        cout << path.front() << " " << path.back() << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_hamiltonian_path(n, adj);

    return 0;
}