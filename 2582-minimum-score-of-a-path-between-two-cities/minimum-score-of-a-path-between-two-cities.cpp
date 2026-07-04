class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto &[nbr, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[nbr])
                dfs(nbr, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};