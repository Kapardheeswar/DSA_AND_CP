#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 100005;

vector<int> graph[MAX_NODES];
int weight[MAX_NODES];
int dp[MAX_NODES][2];

void dfs(int node, int parent) {
    dp[node][0] = 0;
    dp[node][1] = weight[node];

    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            dp[node][0] += max(dp[child][0], dp[child][1]);
            dp[node][1] += dp[child][0];
        }
    }
}

int maxWeightGoodSubset(int tree_nodes, vector<int>& tree_from, vector<int>& tree_to, vector<int>& weight) {
    for (int i = 0; i <= tree_nodes; ++i) {
        graph[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }

    for (int i = 0; i < tree_from.size(); ++i) {
        graph[tree_from[i]].push_back(tree_to[i]);
        graph[tree_to[i]].push_back(tree_from[i]);
    }

    for (int i = 0; i < tree_nodes; ++i) {
        ::weight[i + 1] = weight[i];
    }

    dfs(1, 0);

    return max(dp[1][0], dp[1][1]);
}

int main() {
    int tree_nodes = 3;
    vector<int> tree_from = {1, 1};
    vector<int> tree_to = {2, 3};
    vector<int> weight = {4, 2, 1};

    cout << maxWeightGoodSubset(tree_nodes, tree_from, tree_to, weight) << endl;  // Output: 3

    return 0;
}
