class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {

                vector<int> vals;

             
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        vals.push_back(grid[r][c]);
                    }
                }

                if (vals.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }

                sort(vals.begin(), vals.end());

                int minDiff = INT_MAX;

                for (int x = 1; x < vals.size(); x++) {
                    if (vals[x] != vals[x - 1]) { 
                        minDiff = min(minDiff, vals[x] - vals[x - 1]);
                    }
                }

                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }

        return ans;
    }
};