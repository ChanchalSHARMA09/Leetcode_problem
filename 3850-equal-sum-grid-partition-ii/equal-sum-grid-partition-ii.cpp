class Solution {
public:

    bool check(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        if (m == 1) return false;

        long long total = 0;
        for (auto &r : g)
            for (auto &x : r)
                total += x;

        unordered_set<long long> seen;
        seen.insert(0); // handles "no deletion" case

        long long sum = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += g[i][j];
                seen.insert(g[i][j]);
            }

            long long need = 2LL * sum - total;

            // normal case (rectangle >= 2x2)
            if (i >= 1 && n >= 2 && seen.count(need))
                return true;

            // first row case (only endpoints removable)
            if (i == 0) {
                if (g[0][0] == need || g[0][n - 1] == need || need == 0)
                    return true;
            }

            // single column case
            if (n == 1) {
                if (g[0][0] == need || g[i][0] == need || need == 0)
                    return true;
            }
        }

        return false;
    }

    vector<vector<int>> rotate90(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> r(n, vector<int>(m));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                r[j][m - 1 - i] = g[i][j];

        return r;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        for (int k = 0; k < 4; k++) {
            if (check(grid)) return true;
            grid = rotate90(grid);
        }

        return false;
    }
};