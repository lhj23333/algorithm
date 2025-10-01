#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MIN / 2;

vector<vector<pair<int, ll>>> adj;
vector<vector<ll>> dp;

void dfs(int u, int par) {
    vector<ll> child_max;
    vector<pair<int, ll>> children;
    for (auto [v, w] : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        ll mx = max({dp[v][0], dp[v][1], dp[v][2]});
        child_max.push_back(mx);
        children.push_back({v, w});
    }
    // DP[u][0]: 不选择任何连接u的边
    dp[u][0] = 0;
    for (auto val : child_max) {
        dp[u][0] += val;
    }
    // DP[u][1]: 选择一条边连接到u（到子节点）
    dp[u][1] = INF;
    for (int i = 0; i < children.size(); ++i) {
        auto [v, w] = children[i];
        ll temp = dp[u][0] - child_max[i] + dp[v][1] + w;
        if (temp > dp[u][1]) dp[u][1] = temp;
    }
    // DP[u][2]: 选择两条边连接到u
    dp[u][2] = INF;
    if (children.size() >= 2) {
        vector<ll> gains;
        for (int i = 0; i < children.size(); ++i) {
            auto [v, w] = children[i];
            ll gain = dp[v][1] + w - child_max[i];
            gains.push_back(gain);
        }
        sort(gains.rbegin(), gains.rend());
        dp[u][2] = dp[u][0] + gains[0] + gains[1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dp.assign(n + 1, vector<ll>(3, INF));
    dfs(1, 0);
    ll ans = max({dp[1][0], dp[1][1], dp[1][2]});
    cout << ans << endl;
    return 0;
}