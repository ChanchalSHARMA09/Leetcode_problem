class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> maxDP(m, vector<long long>(n));
        vector<vector<long long>> minDP(m, vector<long long>(n));

        maxDP[0][0] = grid[0][0];
        minDP[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0) continue;

                long long mx = LLONG_MIN;
                long long mn = LLONG_MAX;

                if(i > 0){
                    mx = max(mx, maxDP[i-1][j] * grid[i][j]);
                    mx = max(mx, minDP[i-1][j] * grid[i][j]);

                    mn = min(mn, maxDP[i-1][j] * grid[i][j]);
                    mn = min(mn, minDP[i-1][j] * grid[i][j]);
                }

                if(j > 0){
                    mx = max(mx, maxDP[i][j-1] * grid[i][j]);
                    mx = max(mx, minDP[i][j-1] * grid[i][j]);

                    mn = min(mn, maxDP[i][j-1] * grid[i][j]);
                    mn = min(mn, minDP[i][j-1] * grid[i][j]);
                }

                maxDP[i][j] = mx;
                minDP[i][j] = mn;
            }
        }

        long long ans = maxDP[m-1][n-1];

        if(ans < 0) return -1;
        return ans % MOD;
    }
};